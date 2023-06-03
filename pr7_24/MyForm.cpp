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
using namespace Project718;


[STAThreadAttribute]
int main(array<String^>^ args) {
    std::setlocale(LC_ALL, "Russian");
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    MyForm form;
    Application::Run(% form);
    //сars.clear();
}

inline System::Void Project718::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Создание массива значений X
	std::vector<double> xValues;
	for (double x = 0; x <= 2400; x += 1)
	{
		xValues.push_back(x);
	}

	// Создание массива значений Y
	std::vector<double> yValues;
	for (int i = 0; i < xValues.size(); i++)
	{
		double x = xValues[i];
		double y = CalculateY(x);
		yValues.push_back(y);
	}

	// Привязка данных к элементу управления Chart
	chart1->Series[0]->Points->Clear();
	for (int i = 0; i < xValues.size(); i++)
	{
		chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
	}

	// Настройка внешнего вида графика
	chart1->ChartAreas[0]->AxisX->Minimum = 0;
	chart1->ChartAreas[0]->AxisX->Maximum = +230;
	chart1->ChartAreas[0]->AxisX->Title = "t";
	chart1->ChartAreas[0]->AxisY->Title = "S";
	chart1->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
}
