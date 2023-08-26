#include "KoreMainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kore::KoreMainForm form;
	Application::Run(% form);
}