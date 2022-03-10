#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>

namespace RandomPassGen {

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
	private: System::Windows::Forms::RadioButton^ randomSeedBtn;
	private: System::Windows::Forms::RadioButton^ customSeedBtn;
	private: System::Windows::Forms::TextBox^ seedText;
	private: System::Windows::Forms::Button^ generateBtn;
	private: System::Windows::Forms::TextBox^ generatedText;

	protected:

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
			this->randomSeedBtn = (gcnew System::Windows::Forms::RadioButton());
			this->customSeedBtn = (gcnew System::Windows::Forms::RadioButton());
			this->seedText = (gcnew System::Windows::Forms::TextBox());
			this->generateBtn = (gcnew System::Windows::Forms::Button());
			this->generatedText = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// randomSeedBtn
			// 
			this->randomSeedBtn->AutoSize = true;
			this->randomSeedBtn->Location = System::Drawing::Point(56, 54);
			this->randomSeedBtn->Name = L"randomSeedBtn";
			this->randomSeedBtn->Size = System::Drawing::Size(160, 24);
			this->randomSeedBtn->TabIndex = 0;
			this->randomSeedBtn->TabStop = true;
			this->randomSeedBtn->Text = L"Use random seed";
			this->randomSeedBtn->UseVisualStyleBackColor = true;
			this->randomSeedBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// customSeedBtn
			// 
			this->customSeedBtn->AutoSize = true;
			this->customSeedBtn->Location = System::Drawing::Point(56, 110);
			this->customSeedBtn->Name = L"customSeedBtn";
			this->customSeedBtn->Size = System::Drawing::Size(158, 24);
			this->customSeedBtn->TabIndex = 1;
			this->customSeedBtn->TabStop = true;
			this->customSeedBtn->Text = L"Use custom seed";
			this->customSeedBtn->UseVisualStyleBackColor = true;
			this->customSeedBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::customSeedBtn_CheckedChanged);
			// 
			// seedText
			// 
			this->seedText->Enabled = false;
			this->seedText->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->seedText->Location = System::Drawing::Point(56, 158);
			this->seedText->Name = L"seedText";
			this->seedText->Size = System::Drawing::Size(746, 26);
			this->seedText->TabIndex = 2;
			// 
			// generateBtn
			// 
			this->generateBtn->Location = System::Drawing::Point(56, 226);
			this->generateBtn->Name = L"generateBtn";
			this->generateBtn->Size = System::Drawing::Size(205, 74);
			this->generateBtn->TabIndex = 3;
			this->generateBtn->Text = L"Generate Passwod";
			this->generateBtn->UseVisualStyleBackColor = true;
			this->generateBtn->Click += gcnew System::EventHandler(this, &MyForm::generateBtn_Click);
			// 
			// generatedText
			// 
			this->generatedText->Location = System::Drawing::Point(56, 333);
			this->generatedText->Name = L"generatedText";
			this->generatedText->Size = System::Drawing::Size(746, 26);
			this->generatedText->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 651);
			this->Controls->Add(this->generatedText);
			this->Controls->Add(this->generateBtn);
			this->Controls->Add(this->seedText);
			this->Controls->Add(this->customSeedBtn);
			this->Controls->Add(this->randomSeedBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void customSeedBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->seedText->Enabled = true;
	}
	private: System::Void generateBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ generatedPass;

		if (this->randomSeedBtn->Checked){
			srand(time(NULL));
		} else if (this->customSeedBtn->Checked) {
			srand(System::Convert::ToInt32(this->seedText->Text));
		}
		generatedPass = System::Convert::ToString(rand());
		this->generatedText->Text = generatedPass;
	}
};
}
