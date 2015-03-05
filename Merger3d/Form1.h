#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace Merger3d {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Multiselect = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 26);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(492, 263);
			this->textBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 373);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void MarshalString ( String ^ s, string& os ) {
			using namespace Runtime::InteropServices;
			const char* chars = 
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void MarshalString ( String ^ s, wstring& os ) {
			using namespace Runtime::InteropServices;
			const wchar_t* chars = 
				(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		     	 String ^fname, ^MSG;
				 string name;
				 double lambda, inten;
				 if (openFileDialog1->ShowDialog() == ::System::Windows::Forms::DialogResult::OK ){

					 int numload=openFileDialog1->FileNames->Length;

					 for (int i=0;i<numload;i++){
						 fname=System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileNames[i]);
						 MarshalString(openFileDialog1->FileNames[i],name);
						 ifstream inpfile(name);
						 cout<< name<<" "<<i<<endl;
						 while(inpfile >> lambda >> inten){
						 MSG=MSG+fname+" "+lambda+" "+inten+"\r\n";
						// cout<<" "<<name<<" "<<lambda<<" "<<inten <<endl;
						 }
						 textBox1->Text+=MSG;
						 MSG="";
					 }
				 
				 }
			 }
	};
	}