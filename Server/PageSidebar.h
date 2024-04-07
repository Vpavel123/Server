#pragma once
#include "../Server/NetWorkingUtils/MainServer.h"
#include "Service/NavigationService.h"
#include "PageHome.h"
#include "PageChat.h"
#include <thread>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Server {
	/// <summary>
	/// Сводка для PageSidebar
	/// </summary>
	public ref class PageSidebar : public System::Windows::Forms::UserControl
	{
		void startServer(MainServer* server) {
			std::thread serverThread(&MainServer::handlingAcceptLoop, server);
			serverThread.detach(); 
		}

	public:
		MainServer* server;
		PageHome^ pagehome;
		PageChat^ pagechat;
		Panel^ PageControlServer;

		PageSidebar(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		PageSidebar(MainServer* server)
		{
			this->server = server;
			InitializeComponent();
			
			this->BackColor = System::Drawing::Color().FromArgb(39, 41, 61);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PageSidebar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ mainPanelSidebar;
	private: System::Windows::Forms::RadioButton^ Home;

	private: System::Windows::Forms::RadioButton^ Сhat;
	private: System::Windows::Forms::RadioButton^ Log;
	private: System::Windows::Forms::RadioButton^ Start;
	private: System::Windows::Forms::RadioButton^ Exit;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainPanelSidebar = (gcnew System::Windows::Forms::Panel());
			this->Start = (gcnew System::Windows::Forms::RadioButton());
			this->Exit = (gcnew System::Windows::Forms::RadioButton());
			this->Log = (gcnew System::Windows::Forms::RadioButton());
			this->Сhat = (gcnew System::Windows::Forms::RadioButton());
			this->Home = (gcnew System::Windows::Forms::RadioButton());
			this->mainPanelSidebar->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanelSidebar
			// 
			this->mainPanelSidebar->Controls->Add(this->Start);
			this->mainPanelSidebar->Controls->Add(this->Exit);
			this->mainPanelSidebar->Controls->Add(this->Log);
			this->mainPanelSidebar->Controls->Add(this->Сhat);
			this->mainPanelSidebar->Controls->Add(this->Home);
			this->mainPanelSidebar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanelSidebar->Location = System::Drawing::Point(0, 0);
			this->mainPanelSidebar->Name = L"mainPanelSidebar";
			this->mainPanelSidebar->Size = System::Drawing::Size(300, 673);
			this->mainPanelSidebar->TabIndex = 0;
			// 
			// Start
			// 
			this->Start->Appearance = System::Windows::Forms::Appearance::Button;
			this->Start->AutoSize = true;
			this->Start->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Start->FlatAppearance->BorderSize = 0;
			this->Start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Start->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Start->ForeColor = System::Drawing::SystemColors::Control;
			this->Start->Location = System::Drawing::Point(0, 623);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(300, 50);
			this->Start->TabIndex = 6;
			this->Start->TabStop = true;
			this->Start->Text = L"Start";
			this->Start->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Start->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Start->UseVisualStyleBackColor = true;
			this->Start->CheckedChanged += gcnew System::EventHandler(this, &PageSidebar::Start_CheckedChanged);
			// 
			// Exit
			// 
			this->Exit->Appearance = System::Windows::Forms::Appearance::Button;
			this->Exit->AutoSize = true;
			this->Exit->Dock = System::Windows::Forms::DockStyle::Top;
			this->Exit->FlatAppearance->BorderSize = 0;
			this->Exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Exit->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Exit->ForeColor = System::Drawing::SystemColors::Control;
			this->Exit->Location = System::Drawing::Point(0, 150);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(300, 50);
			this->Exit->TabIndex = 5;
			this->Exit->TabStop = true;
			this->Exit->Text = L"Exit";
			this->Exit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Exit->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->CheckedChanged += gcnew System::EventHandler(this, &PageSidebar::Exit_CheckedChanged);
			// 
			// Log
			// 
			this->Log->Appearance = System::Windows::Forms::Appearance::Button;
			this->Log->AutoSize = true;
			this->Log->Dock = System::Windows::Forms::DockStyle::Top;
			this->Log->FlatAppearance->BorderSize = 0;
			this->Log->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Log->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Log->ForeColor = System::Drawing::SystemColors::Control;
			this->Log->Location = System::Drawing::Point(0, 100);
			this->Log->Name = L"Log";
			this->Log->Size = System::Drawing::Size(300, 50);
			this->Log->TabIndex = 4;
			this->Log->TabStop = true;
			this->Log->Text = L"Log";
			this->Log->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Log->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Log->UseVisualStyleBackColor = true;
			// 
			// Сhat
			// 
			this->Сhat->Appearance = System::Windows::Forms::Appearance::Button;
			this->Сhat->AutoSize = true;
			this->Сhat->Dock = System::Windows::Forms::DockStyle::Top;
			this->Сhat->FlatAppearance->BorderSize = 0;
			this->Сhat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Сhat->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Сhat->ForeColor = System::Drawing::SystemColors::Control;
			this->Сhat->Location = System::Drawing::Point(0, 50);
			this->Сhat->Name = L"Сhat";
			this->Сhat->Size = System::Drawing::Size(300, 50);
			this->Сhat->TabIndex = 3;
			this->Сhat->TabStop = true;
			this->Сhat->Text = L"Сhat";
			this->Сhat->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Сhat->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Сhat->UseVisualStyleBackColor = true;
			this->Сhat->CheckedChanged += gcnew System::EventHandler(this, &PageSidebar::chat_CheckedChanged);
			// 
			// Home
			// 
			this->Home->Appearance = System::Windows::Forms::Appearance::Button;
			this->Home->AutoSize = true;
			this->Home->Dock = System::Windows::Forms::DockStyle::Top;
			this->Home->FlatAppearance->BorderSize = 0;
			this->Home->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Home->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Home->ForeColor = System::Drawing::SystemColors::Control;
			this->Home->Location = System::Drawing::Point(0, 0);
			this->Home->Name = L"Home";
			this->Home->Size = System::Drawing::Size(300, 50);
			this->Home->TabIndex = 2;
			this->Home->TabStop = true;
			this->Home->Text = L"Home";
			this->Home->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Home->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Home->UseVisualStyleBackColor = true;
			this->Home->CheckedChanged += gcnew System::EventHandler(this, &PageSidebar::Home_CheckedChanged);
			// 
			// PageSidebar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->mainPanelSidebar);
			this->Name = L"PageSidebar";
			this->Size = System::Drawing::Size(300, 673);
			this->mainPanelSidebar->ResumeLayout(false);
			this->mainPanelSidebar->PerformLayout();
			this->ResumeLayout(false);

		}

	private: System::Void Home_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate(pagehome, PageControlServer);
	}
	private: System::Void Exit_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void Start_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		server->start();
		startServer(server);
	}
	private: System::Void chat_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate(pagechat, PageControlServer);
	}
};
}
