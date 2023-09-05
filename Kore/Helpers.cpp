#include "KoreMainForm.h"
#include "linker.h"
#include <sstream>
#include <iostream>


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
std::string Parser(char * PE) {
	System::String^ output = "";
	
	PIMAGE_DOS_HEADER dosHeader = {};
	PIMAGE_NT_HEADERS imageNTHeaders = {};
	PIMAGE_SECTION_HEADER sectionHeader = {};
	PIMAGE_SECTION_HEADER importSection = {};
	
	
	// IMAGE_DOS_HEADER
	dosHeader = (PIMAGE_DOS_HEADER)PE;

	// IMAGE_NT_HEADERS
	imageNTHeaders = (PIMAGE_NT_HEADERS)((DWORD)PE + dosHeader->e_lfanew);

	output += "Export Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress + "\r\n\r\n";
	output += "Import Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress + "\r\n\r\n";

	// Going to the section header offset
	DWORD sectionLocation = (DWORD)imageNTHeaders + sizeof(DWORD) + (DWORD)(sizeof(IMAGE_FILE_HEADER)) + (DWORD)imageNTHeaders->FileHeader.SizeOfOptionalHeader;
	DWORD sectionSize = (DWORD)sizeof(IMAGE_SECTION_HEADER);

	// Getting the location to the import directory
	DWORD importDirectoryRVA = imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

	for (int i = 0; i < imageNTHeaders->FileHeader.NumberOfSections; i++) {
		sectionHeader = (PIMAGE_SECTION_HEADER)sectionLocation;
		
		const int n = sizeof(sectionHeader->Name);
		char chars[n + 1];
		memcpy(chars, sectionHeader->Name, n);
		chars[n] = '\0';

		//output += std::stringstream::str(chars);
		printf("\t\t0x%x\t\tVirtual Size\n", sectionHeader->Misc.VirtualSize);
		printf("\t\t0x%x\t\tVirtual Address\n", sectionHeader->VirtualAddress);
		printf("\t\t0x%x\t\tSize Of Raw Data\n", sectionHeader->SizeOfRawData);
		printf("\t\t0x%x\t\tPointer To Raw Data\n", sectionHeader->PointerToRawData);
		printf("\t\t0x%x\t\tPointer To Relocations\n", sectionHeader->PointerToRelocations);
		printf("\t\t0x%x\t\tPointer To Line Numbers\n", sectionHeader->PointerToLinenumbers);
		printf("\t\t0x%x\t\tNumber Of Relocations\n", sectionHeader->NumberOfRelocations);
		printf("\t\t0x%x\t\tNumber Of Line Numbers\n", sectionHeader->NumberOfLinenumbers);
		printf("\t\t0x%x\tCharacteristics\n", sectionHeader->Characteristics);

		// save section that contains import directory table
		if (importDirectoryRVA >= sectionHeader->VirtualAddress && importDirectoryRVA < sectionHeader->VirtualAddress + sectionHeader->Misc.VirtualSize) {
			importSection = sectionHeader;
		}
		sectionLocation += sectionSize;
	}

	return "success";

}