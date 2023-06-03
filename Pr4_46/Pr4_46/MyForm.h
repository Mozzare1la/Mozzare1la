#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

namespace Pr446 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    struct Baggage {
        int itemCount;
        double totalWeight;
    };

    /// <summary>
    /// Сводка для MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        System::ComponentModel::Container^ components; // Объявление переменной components

    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: добавьте код конструктора
            //
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::RichTextBox^ richTextBox1;

        void InitializeComponent() {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Run";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(12, 41);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->ReadOnly = true;
            this->richTextBox1->Size = System::Drawing::Size(304, 208);
            this->richTextBox1->TabIndex = 1;
            this->richTextBox1->Text = L"";
            // 
            // MyForm
            // 
            this->AccessibleName = L" Baggag";
            this->ClientSize = System::Drawing::Size(328, 259);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->richTextBox1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"MyForm";
            this->ResumeLayout(false);

        }

        // Функция для сравнения веса багажа
        static bool CompareBaggage(const Baggage& a, const Baggage& b) {
            return a.totalWeight > b.totalWeight;
        }

        // Обработчик события нажатия кнопки
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            std::vector<Baggage> passengerBaggage{
                {3, 12.5},
                {2, 7.8},
                {1, 4.2},
                {4, 20.1},
                {2, 8.7}
            };

            // 1) Поиск багажа с средним весом одной вещи отличающимся не более чем на 0.3 кг от общего среднего
            double totalWeight = 0.0;
            int totalCount = 0;

            for (const auto& baggage : passengerBaggage) {
                totalWeight += baggage.totalWeight;
                totalCount += baggage.itemCount;
            }

            double averageWeight = totalWeight / totalCount;
            String^ outputText = "";

            for (const auto& baggage : passengerBaggage) {
                double averageItemWeight = baggage.totalWeight / baggage.itemCount;
                if (Math::Abs(averageItemWeight - averageWeight) <= 0.3) {
                    outputText += "Baggage with average item weight within 0.3kg of overall average: "
                        + baggage.itemCount + " items, total weight: " + baggage.totalWeight + "kg\n";
                }
            }

            // 2) Подсчет пассажиров с более чем двумя вещами и с количеством вещей, превышающим среднее
            int passengersWithMoreThanTwoItems = 0;
            int passengersWithMoreThanAverageItems = 0;

            for (const auto& baggage : passengerBaggage) {
                if (baggage.itemCount > 2) {
                    passengersWithMoreThanTwoItems++;
                }
                if (baggage.itemCount > totalCount / passengerBaggage.size()) {
                    passengersWithMoreThanAverageItems++;
                }
            }

            outputText += "Passengers with more than two items: " + passengersWithMoreThanTwoItems + "\n";
            outputText += "Passengers with more than average items: " + passengersWithMoreThanAverageItems + "\n";

            // 3) Проверка наличия пассажира с багажом из одной вещи весом менее 30 кг
            bool passengerWithLightBaggageExists = false;

            for (const auto& baggage : passengerBaggage) {
                if (baggage.itemCount == 1 && baggage.totalWeight < 30.0) {
                    passengerWithLightBaggageExists = true;
                    break;
                }
            }

            outputText += "Passenger with baggage of one item weighing less than 30kg: "
                + (passengerWithLightBaggageExists ? "Yes" : "No") + "\n";

            // 4) Сортировка багажа по невозрастанию веса
            std::sort(passengerBaggage.begin(), passengerBaggage.end(), CompareBaggage);

            outputText += "Sorted baggage by weight (non-increasing order):\n";
            for (const auto& baggage : passengerBaggage) {
                outputText += "Items: " + baggage.itemCount + ", Total weight: " + baggage.totalWeight + "kg\n";
            }

            // 5) Вывод информации о багаже с общим весом менее 10 кг
            outputText += "Baggage with total weight less than 10kg:\n";
            for (const auto& baggage : passengerBaggage) {
                if (baggage.totalWeight < 10.0) {
                    outputText += "Items: " + baggage.itemCount + ", Total weight: " + baggage.totalWeight + "kg\n";
                }
            }

            richTextBox1->Text = outputText;
        }
    };
}