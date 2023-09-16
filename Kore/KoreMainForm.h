#pragma once

#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <debugapi.h>
#include "linker.h"



namespace Kore {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;
	



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

		String^ url = "";


	private: System::Windows::Forms::ToolStripMenuItem^ closeBinaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dllName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ functions;
	private: System::Windows::Forms::Timer^ fadeTimer;
	private: System::Windows::Forms::Timer^ fadeOutTimer;
	private: System::Windows::Forms::ToolStripMenuItem^ creditToolStripMenuItem;



	protected:
		bool loaded = false;

		void setUrl(String^ urlToSet) {
			url = urlToSet;
		}

		void setLoaded(bool setter) {
			loaded = setter;
		}

		void printUrl() {
			OutputDebugStringA(managedStrToNative(url).c_str());
		}

	private: System::Windows::Forms::MenuStrip^ mainMenuStrip;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openBinaryToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ peOutputPg;
	private: System::Windows::Forms::TabPage^ headerInfo;
	private: System::Windows::Forms::TextBox^ peOutputTxtBox;
	private:


	private: System::Windows::Forms::DataGridView^ View;


	private: System::Windows::Forms::ContextMenuStrip^ rightClickSearch;
	private: System::Windows::Forms::ToolStripMenuItem^ searchToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		///
		/// 


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(KoreMainForm::typeid));
			this->mainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openBinaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeBinaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->peOutputPg = (gcnew System::Windows::Forms::TabPage());
			this->peOutputTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->headerInfo = (gcnew System::Windows::Forms::TabPage());
			this->View = (gcnew System::Windows::Forms::DataGridView());
			this->dllName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->rightClickSearch = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->functions = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fadeTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->fadeOutTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->mainMenuStrip->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->peOutputPg->SuspendLayout();
			this->headerInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->View))->BeginInit();
			this->rightClickSearch->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainMenuStrip
			// 
			this->mainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->aboutToolStripMenuItem, this->creditToolStripMenuItem
			});
			this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mainMenuStrip->Name = L"mainMenuStrip";
			this->mainMenuStrip->Size = System::Drawing::Size(601, 24);
			this->mainMenuStrip->TabIndex = 0;
			this->mainMenuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openBinaryToolStripMenuItem,
					this->closeBinaryToolStripMenuItem, this->exitToolStripMenuItem
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
			// closeBinaryToolStripMenuItem
			// 
			this->closeBinaryToolStripMenuItem->Name = L"closeBinaryToolStripMenuItem";
			this->closeBinaryToolStripMenuItem->Size = System::Drawing::Size(139, 22);
			this->closeBinaryToolStripMenuItem->Text = L"Close Binary";
			this->closeBinaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::closeBinaryToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::aboutToolStripMenuItem_Click);
			// 
			// creditToolStripMenuItem
			// 
			this->creditToolStripMenuItem->Name = L"creditToolStripMenuItem";
			this->creditToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->creditToolStripMenuItem->Text = L"Credit";
			this->creditToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::creditToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->peOutputPg);
			this->tabControl1->Controls->Add(this->headerInfo);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(601, 539);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl1->TabIndex = 1;
			// 
			// peOutputPg
			// 
			this->peOutputPg->Controls->Add(this->peOutputTxtBox);
			this->peOutputPg->Location = System::Drawing::Point(4, 22);
			this->peOutputPg->Name = L"peOutputPg";
			this->peOutputPg->Padding = System::Windows::Forms::Padding(3);
			this->peOutputPg->Size = System::Drawing::Size(593, 513);
			this->peOutputPg->TabIndex = 0;
			this->peOutputPg->Text = L"General Info";
			this->peOutputPg->UseVisualStyleBackColor = true;
			// 
			// peOutputTxtBox
			// 
			this->peOutputTxtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->peOutputTxtBox->Location = System::Drawing::Point(3, 3);
			this->peOutputTxtBox->Multiline = true;
			this->peOutputTxtBox->Name = L"peOutputTxtBox";
			this->peOutputTxtBox->ReadOnly = true;
			this->peOutputTxtBox->Size = System::Drawing::Size(587, 507);
			this->peOutputTxtBox->TabIndex = 0;
			// 
			// headerInfo
			// 
			this->headerInfo->Controls->Add(this->View);
			this->headerInfo->Location = System::Drawing::Point(4, 22);
			this->headerInfo->Name = L"headerInfo";
			this->headerInfo->Padding = System::Windows::Forms::Padding(3);
			this->headerInfo->Size = System::Drawing::Size(593, 513);
			this->headerInfo->TabIndex = 1;
			this->headerInfo->Text = L"Header Info";
			this->headerInfo->UseVisualStyleBackColor = true;
			// 
			// View
			// 
			this->View->AllowUserToAddRows = false;
			this->View->AllowUserToDeleteRows = false;
			this->View->AllowUserToOrderColumns = true;
			this->View->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->View->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->View->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
			this->View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->View->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->dllName, this->functions });
			this->View->Location = System::Drawing::Point(6, 3);
			this->View->MultiSelect = false;
			this->View->Name = L"View";
			this->View->ReadOnly = true;
			this->View->Size = System::Drawing::Size(581, 504);
			this->View->TabIndex = 0;
			this->View->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &KoreMainForm::View_CellClick);
			// 
			// dllName
			// 
			this->dllName->ContextMenuStrip = this->rightClickSearch;
			this->dllName->HeaderText = L"Imported DLL";
			this->dllName->Name = L"dllName";
			this->dllName->ReadOnly = true;
			// 
			// rightClickSearch
			// 
			this->rightClickSearch->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->searchToolStripMenuItem });
			this->rightClickSearch->Name = L"rightClickSearch";
			this->rightClickSearch->Size = System::Drawing::Size(110, 26);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->searchToolStripMenuItem->Text = L"Search";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &KoreMainForm::searchToolStripMenuItem_Click);
			// 
			// functions
			// 
			this->functions->ContextMenuStrip = this->rightClickSearch;
			this->functions->HeaderText = L"Functions Used";
			this->functions->Name = L"functions";
			this->functions->ReadOnly = true;
			this->functions->Width = 430;
			// 
			// fadeTimer
			// 
			this->fadeTimer->Enabled = true;
			this->fadeTimer->Tick += gcnew System::EventHandler(this, &KoreMainForm::fadeTimer_Tick);
			// 
			// fadeOutTimer
			// 
			this->fadeOutTimer->Tick += gcnew System::EventHandler(this, &KoreMainForm::fadeOutTimer_Tick);
			// 
			// KoreMainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(601, 566);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->mainMenuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mainMenuStrip;
			this->MaximizeBox = false;
			this->Name = L"KoreMainForm";
			this->Opacity = 0;
			this->Text = L"Kore";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &KoreMainForm::KoreMainForm_FormClosing);
			this->mainMenuStrip->ResumeLayout(false);
			this->mainMenuStrip->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->peOutputPg->ResumeLayout(false);
			this->peOutputPg->PerformLayout();
			this->headerInfo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->View))->EndInit();
			this->rightClickSearch->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion



private: System::Void openBinaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	Stream^ stream;
	OpenFileDialog^ fileDialog = gcnew OpenFileDialog;
	std::string dll;

	fileDialog->InitialDirectory = Directory::GetCurrentDirectory();
	fileDialog->Filter = "All Files (*.*)|*.*";
	fileDialog->FilterIndex = 1;
	fileDialog->Multiselect = false;
	fileDialog->RestoreDirectory = true;

	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		if ((stream = fileDialog->OpenFile()) != nullptr) {
			// Variables to hold output from Parser
			String^ output;
			List<String^> imports;
			List<String^> funcs;
			
			// Used for cleaning up the strings from Parser
			char separator = ' ';
			bool checker = true;
			
			// Remove any previous loads from other PE files
			peOutputTxtBox->Text = "";
			url = "";
			View->Rows->Clear();

			// Change state to file loaded
			setLoaded(true);

			std::string fileName = managedStrToNative(fileDialog->FileName);
			
			std::uintmax_t fileSize = std::filesystem::file_size(fileName);
			
			char* buf = new char[fileSize];

			std::ifstream fin(fileName, std::ios::binary);

			fin.read(buf, fileSize);

			if (!fin) { peOutputTxtBox->Text += "Error Reading File"; }

			fin.close();

			peOutputTxtBox->Text += "File Name: " + fileDialog->FileName + "\r\n\r\n";
			peOutputTxtBox->Text += "File Type: " + Path::GetExtension(fileDialog->FileName) + "\r\n\r\n";
			peOutputTxtBox->Text += "File Size: " + Math::Round((FileInfo(fileDialog->FileName).Length / 1048576), 2) + " MB";
			
			output = Parser(buf, checker);

			//peOutputTxtBox->Text += output;
			
			std::istringstream importStream(managedStrToNative(output));
			while (std::getline(importStream, dll, separator)) {
				
				// Check for space and don't include that in data grid
				std::ws(importStream);

				String^ temp = gcnew System::String(dll.data());

				imports.Add(temp);
			}
			checker = false;

			output = Parser(buf, checker);
			
			separator = '|';
			
			std::istringstream funcStream(managedStrToNative(output));
			while (std::getline(funcStream, dll, separator)) {

				// Check for | and don't include that in data grid
				std::ws(funcStream);

				String^ temp = gcnew System::String(dll.data());

				funcs.Add(temp);
			}

			// Add to datagrid
			for each (String^ d in imports) {
				for each (String^ f in funcs) {
					View->Rows->Add(d, f);
				}
			}

			stream->Close();
		}
	}
	}


private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	startAbout();

}
private: System::Void searchToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ query = "https://www.google.com/search?q=" + url;
	if (url != "") {

		Process::Start(query);
	}
	
}
private: System::Void View_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	
	try {
		if (loaded) {

			if (View->SelectedCells->Count == 1) {
				setUrl(View->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());
			}
		}
	}
	catch (System::ArgumentOutOfRangeException^ e) {
		
	}
	
	
}
private: System::Void closeBinaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	peOutputTxtBox->Text = "";
	View->Rows->Clear();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	fadeOutTimer->Start();

	
}
private: System::Void fadeTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (Opacity == 1) {
		fadeTimer->Stop();
	}
	else {
		Opacity += 0.1;
	}
}


private: System::Void KoreMainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	
	while (Opacity > 0) {
		Sleep(100);
		Opacity -= 0.1;
	}

	exit(0);
}
private: System::Void fadeOutTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (Opacity == 0) {
		fadeOutTimer->Stop();
		exit(0);
	}
	else {
		Opacity -= 0.1;
	}
}
private: System::Void creditToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show("Icon by Icons8. Visit Website?", "Credit", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
		
		Process::Start("https://icons8.com/icon/12929/software");
	}
}
};


}
