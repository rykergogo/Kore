#include "KoreMainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	FreeConsole();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kore::KoreMainForm form;
	form.StartPosition = FormStartPosition::CenterScreen;
	Application::Run(% form);
}