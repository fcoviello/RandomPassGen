#pragma once
#include <iostream>
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ lengthText;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ exitBtn;
	private: System::Windows::Forms::Button^ copyBtn;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lengthText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->copyBtn = (gcnew System::Windows::Forms::Button());
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
			this->randomSeedBtn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::randomSeedBtn_CheckedChanged);
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
			this->seedText->Size = System::Drawing::Size(274, 26);
			this->seedText->TabIndex = 2;
			// 
			// generateBtn
			// 
			this->generateBtn->Location = System::Drawing::Point(56, 276);
			this->generateBtn->Name = L"generateBtn";
			this->generateBtn->Size = System::Drawing::Size(274, 74);
			this->generateBtn->TabIndex = 3;
			this->generateBtn->Text = L"Generate Passwod";
			this->generateBtn->UseVisualStyleBackColor = true;
			this->generateBtn->Click += gcnew System::EventHandler(this, &MyForm::generateBtn_Click);
			// 
			// generatedText
			// 
			this->generatedText->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->generatedText->Location = System::Drawing::Point(56, 385);
			this->generatedText->Multiline = true;
			this->generatedText->Name = L"generatedText";
			this->generatedText->Size = System::Drawing::Size(274, 101);
			this->generatedText->TabIndex = 4;
			this->generatedText->TextChanged += gcnew System::EventHandler(this, &MyForm::generatedText_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 225);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Length:";
			// 
			// lengthText
			// 
			this->lengthText->Location = System::Drawing::Point(121, 222);
			this->lengthText->MaxLength = 3;
			this->lengthText->Name = L"lengthText";
			this->lengthText->Size = System::Drawing::Size(100, 26);
			this->lengthText->TabIndex = 7;
			this->lengthText->Text = L"8";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(227, 225);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"(max 999)";
			// 
			// exitBtn
			// 
			this->exitBtn->Location = System::Drawing::Point(56, 521);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(274, 74);
			this->exitBtn->TabIndex = 9;
			this->exitBtn->Text = L"Exit";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// copyBtn
			// 
			this->copyBtn->Location = System::Drawing::Point(341, 385);
			this->copyBtn->Name = L"copyBtn";
			this->copyBtn->Size = System::Drawing::Size(75, 101);
			this->copyBtn->TabIndex = 10;
			this->copyBtn->Text = L"Copy";
			this->copyBtn->UseVisualStyleBackColor = true;
			this->copyBtn->Click += gcnew System::EventHandler(this, &MyForm::copyBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(428, 644);
			this->Controls->Add(this->copyBtn);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lengthText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->generatedText);
			this->Controls->Add(this->generateBtn);
			this->Controls->Add(this->seedText);
			this->Controls->Add(this->customSeedBtn);
			this->Controls->Add(this->randomSeedBtn);
			this->ForeColor = System::Drawing::SystemColors::WindowText;
			this->MaximumSize = System::Drawing::Size(450, 700);
			this->MinimumSize = System::Drawing::Size(450, 700);
			this->Name = L"MyForm";
			this->Text = L"Random Pass Gen";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void randomSeedBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void customSeedBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void generateBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void generatedText_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void copyBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
