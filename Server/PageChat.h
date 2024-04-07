#pragma once
#include "../Server/NetWorkingUtils/MainServer.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Server {

	/// <summary>
	/// —водка дл€ PageChat
	/// </summary>
	public ref class PageChat : public System::Windows::Forms::UserControl
	{
	public:
		MainServer* server;
		PageChat(void)
		{
			InitializeComponent();
		}

		PageChat(MainServer* server)
		{
			this->server = server;
			InitializeComponent();

			this->BackColor = System::Drawing::Color().FromArgb(30, 30, 40);
			this->ChatTextBox->BackColor = System::Drawing::Color().FromArgb(39, 41, 61);
			this->ChatBox->BackColor = System::Drawing::Color().FromArgb(30, 30, 40);

		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~PageChat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ ChatTextBox;
	private: System::Windows::Forms::RichTextBox^ ChatBox;

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ChatTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ChatBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// ChatTextBox
			// 
			this->ChatTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ChatTextBox->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->ChatTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChatTextBox->ForeColor = System::Drawing::SystemColors::Control;
			this->ChatTextBox->Location = System::Drawing::Point(0, 551);
			this->ChatTextBox->Name = L"ChatTextBox";
			this->ChatTextBox->Size = System::Drawing::Size(962, 122);
			this->ChatTextBox->TabIndex = 0;
			this->ChatTextBox->Text = L"";
			this->ChatTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PageChat::ChatTextBox_KeyDown);
			// 
			// ChatBox
			// 
			this->ChatBox->BackColor = System::Drawing::Color::Black;
			this->ChatBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ChatBox->Font = (gcnew System::Drawing::Font(L"Lucida Console", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ChatBox->ForeColor = System::Drawing::SystemColors::Control;
			this->ChatBox->Location = System::Drawing::Point(22, 19);
			this->ChatBox->Name = L"ChatBox";
			this->ChatBox->Size = System::Drawing::Size(920, 514);
			this->ChatBox->TabIndex = 1;
			this->ChatBox->Text = L"";
			// 
			// PageChat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->ChatBox);
			this->Controls->Add(this->ChatTextBox);
			this->Name = L"PageChat";
			this->Size = System::Drawing::Size(962, 673);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ChatTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			std::string unmanagedString = msclr::interop::marshal_as<std::string>(ChatTextBox->Text);
			server->SendData(unmanagedString);
			ChatBox->Text += ChatTextBox->Text + "\n";
			ChatTextBox->Clear();
			e->SuppressKeyPress = true;
		}
	}
	};
}
