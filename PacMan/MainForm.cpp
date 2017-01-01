#include "MainForm.h"
#include "Engine.h"
#include <iostream>


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<System::String^>^ args) {
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
Engine engine;

WindowForm::MainForm form(engine);

Application::Run(%form);
engine.stop();
form.stop();
}
	
