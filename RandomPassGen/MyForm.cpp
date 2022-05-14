#include "MyForm.h"
#include <Windows.h>
#include <msclr\marshal_cppstd.h>

using namespace RandomPassGen;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void MyForm::randomSeedBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->seedText->Enabled = false;
}

System::Void MyForm::customSeedBtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
{
	this->seedText->Enabled = true;
}

System::Void MyForm::generateBtn_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::String^ generatedPass;
	System::Char generatedChar;
	System::Char forbiddenChars[] = { '`','^','*','(',')','{','}','[',']',':',';','\'','\"',',','.','\\','/' };
	int iterations;
	int iCustomSeed = 0;
	bool forbiddedCharFound = false;

	if (this->randomSeedBtn->Checked) {
		srand(time(NULL));
	}
	else if (this->customSeedBtn->Checked) {
		for (int i = 0; i < this->seedText->Text->Length; i++) {
			iCustomSeed += (int)System::Convert::ToInt32(this->seedText->Text[i]);
		}
		srand(iCustomSeed);
	}

	iterations = System::Convert::ToInt16(this->lengthText->Text);
	for (int i = 0; i < iterations; i++) {
		do {
			forbiddedCharFound = false;
			// Generate random character
			generatedChar = System::Convert::ToChar((rand() % 90) + 33);
			// Check if it's a forbidden char
			for (int x = 0; x < (sizeof(forbiddenChars) / sizeof(System::Char)); x++) {
				if (generatedChar == forbiddenChars[x]) {
					forbiddedCharFound = true;
					break;
				}
			}
		} while (forbiddedCharFound == true);

		// Add char to generated string
		generatedPass += generatedChar;
	}
	this->generatedText->Text = generatedPass;
}

System::Void MyForm::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{

}

System::Void MyForm::generatedText_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{

}

System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	exit(0);
}

System::Void MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{

}

System::Void MyForm::copyBtn_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string sText = msclr::interop::marshal_as<std::string>(this->generatedText->Text);
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, sText.size()+1);
	
	OpenClipboard(NULL);
	EmptyClipboard();
	memcpy(GlobalLock(hg), sText.c_str(), sText.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg); 
	CloseClipboard();
}