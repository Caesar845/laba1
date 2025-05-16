#pragma once
#include <cmath>
#include <string>
namespace laba1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonCalc;
	private: System::Windows::Forms::TextBox^ textBoxX;
	private: System::Windows::Forms::TextBox^ textBoxOutput;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(31, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть х";
			// 
			// buttonCalc
			// 
			this->buttonCalc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCalc->Location = System::Drawing::Point(56, 167);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(92, 31);
			this->buttonCalc->TabIndex = 1;
			this->buttonCalc->Text = L"Обчислити";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &MyForm::buttonCalc_Click);
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(37, 112);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(79, 20);
			this->textBoxX->TabIndex = 2;
			// 
			// textBoxOutput
			// 
			this->textBoxOutput->Location = System::Drawing::Point(37, 232);
			this->textBoxOutput->Name = L"textBoxOutput";
			this->textBoxOutput->Size = System::Drawing::Size(356, 20);
			this->textBoxOutput->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 295);
			this->Controls->Add(this->textBoxOutput);
			this->Controls->Add(this->textBoxX);
			this->Controls->Add(this->buttonCalc);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
		double x = Convert::ToDouble(textBoxX->Text);
		
		if (x == 0) {
			textBoxOutput->Text = "Помилка: ділення на 0 неможливе.";
			return;
		}
		if (x < 0) {
			textBoxOutput->Text = "Помилка: корінь з від’ємного числа.";
			return;
		}

		double numerator = 2 * x + sin(x) + pow(0.5, x) / x;
		double denominator = pow(cos(x), 2) + pow(x, 2) + sqrt(x);
		double y = numerator / denominator;

		textBoxOutput->Text = "Варіант 6 - Обчислення значення функції\n";
		textBoxOutput->AppendText("x = " + x.ToString("F2") + "\r\n");
		textBoxOutput->AppendText("y = " + y.ToString("F6"));
	}
	catch (FormatException^) {
		textBoxOutput->Text = "Помилка: введено некоректне значення.";
	}
	}
	};
}
