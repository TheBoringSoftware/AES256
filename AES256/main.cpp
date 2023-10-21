#include"gui.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
 
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPreviousInstance, PSTR lpCmdLine, int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AES256::gui form;
	Application::Run(% form);
	return 0;
}
