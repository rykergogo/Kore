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