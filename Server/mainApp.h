#pragma once
#include "NetWorkingUtils/MainServer.h"
#include "Service/NavigationService.h"
#include "PageSidebar.h"
#include "PageChat.h"
#include "PageHome.h"

namespace Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ mainApp
	/// </summary>
	public ref class mainApp : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Panel^ pageMainpanel;
		MainServer* server;
		PageHome^ pagehome;
		PageChat^ pagechat;
		PageSidebar^ pagesidebar;

		mainApp(void)
		{
			InitializeComponent();
			server = new MainServer();
			pagehome = gcnew PageHome();
			pagechat = gcnew PageChat(server);
			pagesidebar = gcnew PageSidebar(server);

			pagesidebar->pagehome = pagehome;
			pagesidebar->pagechat = pagechat;
			pagesidebar->PageControlServer = pageMainpanel;

			this->BackColor = System::Drawing::Color().FromArgb(30, 30, 40);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~mainApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;


	private: System::Windows::Forms::Panel^ PageSidebarPanel;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pageMainpanel = (gcnew System::Windows::Forms::Panel());
			this->PageSidebarPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pageMainpanel);
			this->panel1->Controls->Add(this->PageSidebarPanel);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1262, 673);
			this->panel1->TabIndex = 0;
			// 
			// pageMainpanel
			// 
			this->pageMainpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pageMainpanel->Location = System::Drawing::Point(300, 0);
			this->pageMainpanel->Name = L"pageMainpanel";
			this->pageMainpanel->Size = System::Drawing::Size(962, 673);
			this->pageMainpanel->TabIndex = 1;
			// 
			// PageSidebarPanel
			// 
			this->PageSidebarPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->PageSidebarPanel->Location = System::Drawing::Point(0, 0);
			this->PageSidebarPanel->Name = L"PageSidebarPanel";
			this->PageSidebarPanel->Size = System::Drawing::Size(300, 673);
			this->PageSidebarPanel->TabIndex = 0;
			// 
			// mainApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->panel1);
			this->Name = L"mainApp";
			this->Text = L"Server";
			this->Load += gcnew System::EventHandler(this, &mainApp::mainApp_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainApp_Load(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate(this->pagesidebar, PageSidebarPanel);
		NavigationService::getInstance()->Navigate(this->pagehome, pageMainpanel);
	}

	};
}
