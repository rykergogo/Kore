#include "KoreMainForm.h"
#include "linker.h"


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
std::string Parser(char * PE, System::Windows::Forms::TextBox^ peOutputTxtBox) {
	PIMAGE_DOS_HEADER dosHeader = {};
	PIMAGE_NT_HEADERS imageNTHeaders = {};
	
	
	// IMAGE_DOS_HEADER
	dosHeader = (PIMAGE_DOS_HEADER)PE;

	// IMAGE_NT_HEADERS
	imageNTHeaders = (PIMAGE_NT_HEADERS)((DWORD)PE + dosHeader->e_lfanew);

	peOutputTxtBox->Text += "Export Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress;
	peOutputTxtBox->Text += "Import Directory Address: " + imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress;

	return "success";

}