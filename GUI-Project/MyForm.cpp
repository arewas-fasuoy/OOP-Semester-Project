#include "MyForm.h"
#include "MyForm1.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyTest::MyForm form;
	Application::Run(% form);
}

