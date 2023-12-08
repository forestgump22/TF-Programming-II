#include "FormPresentation.h"
using namespace System;
using namespace System::Windows::Forms;
int main() {
	Application::EnableVisualStyles();
	Application::Run(gcnew(TFINAL::FormPresentation));
	return 0;
}

