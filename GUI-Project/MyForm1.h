#pragma once
#include <string>
#include <fstream>
#include <istream>
#include <streambuf>
#include <iostream>
#include <sstream>
#include <msclr\marshal_cppstd.h>
#include "Header.h"

namespace MyTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(std::string str1, std::string str2, std::string str3)
		{
			InitializeComponent();
			//function where all taxes are calculated
			mainLogic(str1, str2, str3);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->Location = System::Drawing::Point(51, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(311, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"YOUR CALCULATED TOLL TAX";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(34, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"TOLL TAX :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(34, 192);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(169, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"OTHER TAXES :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(34, 233);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"FINE :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(34, 276);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"TOTAL :";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(159, 325);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 37);
			this->button1->TabIndex = 5;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(155, 150);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 24);
			this->label6->TabIndex = 6;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(209, 192);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 24);
			this->label7->TabIndex = 7;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(109, 233);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(21, 24);
			this->label8->TabIndex = 8;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(134, 276);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 24);
			this->label9->TabIndex = 9;
			this->label9->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(12, 85);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 16);
			this->label10->TabIndex = 10;
			this->label10->Text = L"STATEMENT";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(494, 402);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"TOLL PLAZA MANAGEMENT SYSTEM";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public:  void  mainLogic(std::string test1, std::string test2, std::string test3) {
		vehicle* obj1;
		valid obj, * obj2;
		obj1 = &obj;
		int total;
		int fine;
		int tax;
		int toll_tax;
		string temp;

		if (obj1->license(test2)) {
			if (obj1->registeration(test1)) {
				if (obj1->taxes_()) {
					total = obj2->calculate_tax(test3);
					fine = obj2->get_fine();
					tax = obj2->get_tax();
					toll_tax = obj2->get_toll_tax();
					temp = obj2->get_statement();

				}
				else {
					non_paid1 P;
					obj2 = &P;
					total = obj2->calculate_tax(test3);
					fine = obj2->get_fine();
					tax = obj2->get_tax();
					toll_tax = obj2->get_toll_tax();
					temp = obj2->get_statement();
				}
			}
			else {
				non_registered1 A;
				obj2 = &A;
				total = obj2->calculate_tax(test3);
				fine = obj2->get_fine();
				tax = obj2->get_tax();
				toll_tax = obj2->get_toll_tax();
				temp = obj2->get_statement();
			}
		}
		else {
			invalid I, * b;
			obj1 = &I;
			if (obj1->registeration(test1)) {
				if (obj1->taxes_()) {
					total = b->calculate_tax(test3);
					fine = b->get_fine();
					tax = b->get_tax();
					toll_tax = b->get_toll_tax();
					temp = b->get_statement();
				}
				else {
					non_paid2 P;
					b = &P;
					total = b->calculate_tax(test3);
					fine = b->get_fine();
					tax = b->get_tax();
					toll_tax = b->get_toll_tax();
					temp = b->get_statement();


				}
			}
			else {
				non_registered2 A;
				b = &A;
				total = b->calculate_tax(test3);
				fine = b->get_fine();
				tax = b->get_tax();
				toll_tax = b->get_toll_tax();
				temp = b->get_statement();
			}

		}
		stringstream ss, aa, bb, cc;
		String^ L = gcnew
			String(temp.c_str());
		//for label 6
		ss << toll_tax << endl;
		string a = ss.str();
		String^ s = gcnew
			String(a.c_str());
		label6->Text = s;
		//for label 7
		aa << tax << endl;
		string b = aa.str();
		String^ t = gcnew
			String(b.c_str());
		label7->Text = t;
		//for label 8
		bb << fine << endl;
		string c = bb.str();
		String^ u = gcnew
			String(c.c_str());
		label8->Text = u;
		//for label 9
		cc << total << endl;
		string d = cc.str();
		String^ v = gcnew
			String(d.c_str());
		label9->Text = v;
		//for displaying statement 
		label10->Text = L;

	}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
	};
}