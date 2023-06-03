#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MyForm.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace Pr446;

struct Baggage {
    int itemCount;
    double totalWeight;
};

[STAThreadAttribute]
int main(array<String^>^ args) {
    std::setlocale(LC_ALL, "Russian");
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm form;
    Application::Run(% form);
}