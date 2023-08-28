#pragma once
#include <iostream>
#include "linker.h"
#include <Windows.h>
#include <WinUser.h>
#include <filesystem>
#include <fstream>



namespace Kore {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Summary for KoreMainForm
	/// </summary>
	public ref class KoreMainForm : public System::Windows::Forms::Form
	{
	public:
		KoreMainForm(void)
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
		~KoreMainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ mainMenuStrip;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openBinaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ peOutputPg;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ peOutputTxtBox;


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
			this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openBinaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->peOutputPg = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->peOutputTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->mainMenuStrip->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->peOutputPg->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainMenuStrip
			// 
			this->mainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mainMenuStrip->Name = L"mainMenuStrip";
			this->mainMenuStrip->Size = System::Drawing::Size(572, 24);
			this->mainMenuStrip->TabIndex = 0;
			this->mainMenuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openBinaryToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openBinaryToolStripMenuItem
			// 
			this->openBinaryToolStripMenuItem->Name = L"openBinaryToolStripMenuItem";
			this->openBinaryToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->openBinaryToolStripMenuItem->Text = L"Open Binary";
			this->openBinaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::openBinaryToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::exitToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->peOutputPg);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(548, 435);
			this->tabControl1->TabIndex = 1;
			// 
			// peOutputPg
			// 
			this->peOutputPg->Controls->Add(this->peOutputTxtBox);
			this->peOutputPg->Location = System::Drawing::Point(4, 22);
			this->peOutputPg->Name = L"peOutputPg";
			this->peOutputPg->Padding = System::Windows::Forms::Padding(3);
			this->peOutputPg->Size = System::Drawing::Size(540, 409);
			this->peOutputPg->TabIndex = 0;
			this->peOutputPg->Text = L"PE Output";
			this->peOutputPg->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(192, 74);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// peOutputTxtBox
			// 
			this->peOutputTxtBox->Location = System::Drawing::Point(6, 6);
			this->peOutputTxtBox->Multiline = true;
			this->peOutputTxtBox->Name = L"peOutputTxtBox";
			this->peOutputTxtBox->ReadOnly = true;
			this->peOutputTxtBox->Size = System::Drawing::Size(528, 397);
			this->peOutputTxtBox->TabIndex = 0;
			// 
			// KoreMainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 474);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->mainMenuStrip);
			this->MainMenuStrip = this->mainMenuStrip;
			this->Name = L"KoreMainForm";
			this->Text = L"KoreMainForm";
			this->mainMenuStrip->ResumeLayout(false);
			this->mainMenuStrip->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->peOutputPg->ResumeLayout(false);
			this->peOutputPg->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}


private: System::Void openBinaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	Stream^ stream;
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog;

	fileDialog->InitialDirectory = Directory::GetCurrentDirectory();
	fileDialog->Filter = "Exe Files (*.exe)|*.exe";
	fileDialog->FilterIndex = 1;
	fileDialog->Multiselect = false;
	fileDialog->RestoreDirectory = true;

	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if ((stream = fileDialog->OpenFile()) != nullptr) {

			std::string fileName = managedStrToNative(fileDialog->FileName);
			
			std::uintmax_t fileSize = std::filesystem::file_size(fileName);
			
			char* buf = new char[fileSize];

			std::ifstream fin(fileName, std::ios::binary);

			fin.read(buf, fileSize);

			if (!fin) { std::cout << "Error reading file"; }

			fin.close();

			peOutputTxtBox->Text += "File Name: ";
			
			

			stream->Close();
		}
	}
	}
};
}
