#include "KoreMainForm.h"
#include "linker.h"
#include <iostream>
#include <debugapi.h>


// Function implemented from: https://stackoverflow.com/questions/17789807/converting-managed-systemstring-to-stdstring-in-c-cli
std::string managedStrToNative(System::String^ sysstr)
{
	using System::IntPtr;
	using System::Runtime::InteropServices::Marshal;

	IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
	std::string outString = static_cast<const char*>(ip.ToPointer());
	Marshal::FreeHGlobal(ip);
	return outString;
}

/*

 Parse the PE file

 Parsing info: https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/pe-file-header-parser-in-c++

*/
System::String^ Parser(char * PE) {
	System::String^ output = "";
	
	PIMAGE_DOS_HEADER dosHeader = {};
	PIMAGE_NT_HEADERS imageNTHeaders = {};
	PIMAGE_SECTION_HEADER sectionHeader = {};
	PIMAGE_SECTION_HEADER importSection = {};
	IMAGE_IMPORT_DESCRIPTOR* importDescriptor = {};

	PIMAGE_THUNK_DATA thunkData = {};
	DWORD thunk = NULL;

	DWORD rawOffset = NULL;
	
	
	// IMAGE_DOS_HEADER
	dosHeader = (PIMAGE_DOS_HEADER)PE;

	// IMAGE_NT_HEADERS
	imageNTHeaders = (PIMAGE_NT_HEADERS)((DWORD)PE + dosHeader->e_lfanew);

	// Decided not helpful for analysis
	//output += "Export Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress + "\r\n\r\n";
	//output += "Import Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress + "\r\n\r\n";
	

	// Going to the section header offset
	DWORD sectionLocation = (DWORD)imageNTHeaders + sizeof(DWORD) + (DWORD)(sizeof(IMAGE_FILE_HEADER)) + (DWORD)imageNTHeaders->FileHeader.SizeOfOptionalHeader;
	DWORD sectionSize = (DWORD)sizeof(IMAGE_SECTION_HEADER);

	// Getting the location to the import directory
	DWORD importDirectoryRVA = imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

	for (int i = 0; i < imageNTHeaders->FileHeader.NumberOfSections; i++) {
		sectionHeader = (PIMAGE_SECTION_HEADER)sectionLocation;

		// save section that contains import directory table
		if (importDirectoryRVA >= sectionHeader->VirtualAddress && importDirectoryRVA < sectionHeader->VirtualAddress + sectionHeader->Misc.VirtualSize) {
			importSection = sectionHeader;
		}
		sectionLocation += sectionSize;

	}

	// offset to import table
	rawOffset = (DWORD)PE + importSection->PointerToRawData;

	// pointer to import descriptor's file offset
	importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(rawOffset + (imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress - importSection->VirtualAddress));



	for (; importDescriptor->Name != 0; importDescriptor++) {
		
		// Imports
		System::String^ name = gcnew System::String((LPCSTR)rawOffset + (importDescriptor->Name - importSection->VirtualAddress));
		
		output += name + " ";

		thunk = importDescriptor->OriginalFirstThunk == 0 ? importDescriptor->FirstThunk : importDescriptor->OriginalFirstThunk;
		thunkData = (PIMAGE_THUNK_DATA)(rawOffset + (thunk - importSection->VirtualAddress));

		// dll exported functions
		for (; thunkData->u1.AddressOfData != 0; thunkData++) {
			//a cheap and probably non-reliable way of checking if the function is imported via its ordinal number
			if (thunkData->u1.AddressOfData > 0x80000000) {
				//show lower bits of the value to get the ordinal
				printf("\t\tOrdinal: %x\n", (WORD)thunkData->u1.AddressOfData);
			}
			else {
				printf("\t\t%s\n", (rawOffset + (thunkData->u1.AddressOfData - importSection->VirtualAddress + 2)));
			}
		}
	}

	return output;

}