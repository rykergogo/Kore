#include "AboutForm.h"

using namespace System::Windows::Forms;



void startAbout()
{
	Kore::AboutForm form;
	form.StartPosition = FormStartPosition::CenterScreen;
	form.ShowDialog();
}