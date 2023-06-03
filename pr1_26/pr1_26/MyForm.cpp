#include <msclr\marshal_cppstd.h>
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
using namespace pr126;

int countRightTriangles() {
    int count = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = a; b < 100; b++) {
            for (int c = b; c < 100; c++) {
                // Проверка условия прямоугольности с использованием теоремы Пифагора
                if (a * a + b * b == c * c) {
                    count++;
                }
            }
        }
    }
    return count;
}

[STAThreadAttribute]
int main(array<String^>^ args) {
    std::setlocale(LC_ALL, "Russian");
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm form;
    Application::Run(% form);
}

System::Void pr126::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    int count = countRightTriangles();
    textBox1->Text = Convert::ToString(count);
}
