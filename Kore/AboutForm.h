#pragma once

namespace Kore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
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
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ authorLbl;
	private: System::Windows::Forms::Button^ githubBtn;
	private: System::Windows::Forms::Label^ emailLbl;
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
			this->authorLbl = (gcnew System::Windows::Forms::Label());
			this->githubBtn = (gcnew System::Windows::Forms::Button());
			this->emailLbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// authorLbl
			// 
			this->authorLbl->AutoSize = true;
			this->authorLbl->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authorLbl->Location = System::Drawing::Point(14, 9);
			this->authorLbl->Name = L"authorLbl";
			this->authorLbl->Size = System::Drawing::Size(220, 21);
			this->authorLbl->TabIndex = 0;
			this->authorLbl->Text = L"Author: Ryker Gogolkiewicz";
			// 
			// githubBtn
			// 
			this->githubBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->githubBtn->Location = System::Drawing::Point(41, 84);
			this->githubBtn->Name = L"githubBtn";
			this->githubBtn->Size = System::Drawing::Size(165, 27);
			this->githubBtn->TabIndex = 1;
			this->githubBtn->Text = L"My Other Projects";
			this->githubBtn->UseVisualStyleBackColor = true;
			this->githubBtn->Click += gcnew System::EventHandler(this, &AboutForm::githubBtn_Click);
			// 
			// emailLbl
			// 
			this->emailLbl->AutoSize = true;
			this->emailLbl->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailLbl->Location = System::Drawing::Point(37, 30);
			this->emailLbl->Name = L"emailLbl";
			this->emailLbl->Size = System::Drawing::Size(169, 19);
			this->emailLbl->TabIndex = 3;
			this->emailLbl->Text = L"@rykergogo1@gmail.com";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(247, 159);
			this->Controls->Add(this->emailLbl);
			this->Controls->Add(this->githubBtn);
			this->Controls->Add(this->authorLbl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AboutForm";
			this->Text = L"About";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void githubBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Process::Start("https://github.com/rykergogo");

	}
	};
}
