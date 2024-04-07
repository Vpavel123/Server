#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Server {

	/// <summary>
	/// —водка дл€ PageHome
	/// </summary>
	public ref class PageHome : public System::Windows::Forms::UserControl
	{
	public:
		PageHome(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			panelInfo->BackColor = System::Drawing::Color().FromArgb(39, 41, 61);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~PageHome()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelInfo;
	private: System::Windows::Forms::Panel^ panelTimeRun;

	protected:

	protected:

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panelTimeSet;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ LabelTimeRun;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ LabelStartTime;


	private: System::Windows::Forms::Label^ UpTimeRun;
	private: System::Windows::Forms::Label^ StartTime;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PageHome::typeid));
			this->panelInfo = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panelTimeSet = (gcnew System::Windows::Forms::Panel());
			this->StartTime = (gcnew System::Windows::Forms::Label());
			this->LabelStartTime = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panelTimeRun = (gcnew System::Windows::Forms::Panel());
			this->UpTimeRun = (gcnew System::Windows::Forms::Label());
			this->LabelTimeRun = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelInfo->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panelTimeSet->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panelTimeRun->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelInfo
			// 
			this->panelInfo->Controls->Add(this->panel4);
			this->panelInfo->Controls->Add(this->panelTimeSet);
			this->panelInfo->Controls->Add(this->panelTimeRun);
			this->panelInfo->Location = System::Drawing::Point(49, 50);
			this->panelInfo->Name = L"panelInfo";
			this->panelInfo->Size = System::Drawing::Size(859, 178);
			this->panelInfo->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Location = System::Drawing::Point(575, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(280, 172);
			this->panel4->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(24, 49);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(90, 82);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// panelTimeSet
			// 
			this->panelTimeSet->Controls->Add(this->StartTime);
			this->panelTimeSet->Controls->Add(this->LabelStartTime);
			this->panelTimeSet->Controls->Add(this->pictureBox2);
			this->panelTimeSet->Location = System::Drawing::Point(289, 3);
			this->panelTimeSet->Name = L"panelTimeSet";
			this->panelTimeSet->Size = System::Drawing::Size(280, 172);
			this->panelTimeSet->TabIndex = 1;
			// 
			// StartTime
			// 
			this->StartTime->AutoSize = true;
			this->StartTime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->StartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartTime->ForeColor = System::Drawing::SystemColors::Control;
			this->StartTime->Location = System::Drawing::Point(144, 101);
			this->StartTime->Name = L"StartTime";
			this->StartTime->Size = System::Drawing::Size(119, 30);
			this->StartTime->TabIndex = 4;
			this->StartTime->Text = L"04.04.2024";
			this->StartTime->Click += gcnew System::EventHandler(this, &PageHome::StartTime_Click);
			// 
			// LabelStartTime
			// 
			this->LabelStartTime->AutoSize = true;
			this->LabelStartTime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LabelStartTime->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelStartTime->ForeColor = System::Drawing::SystemColors::Control;
			this->LabelStartTime->Location = System::Drawing::Point(144, 58);
			this->LabelStartTime->Name = L"LabelStartTime";
			this->LabelStartTime->Size = System::Drawing::Size(117, 30);
			this->LabelStartTime->TabIndex = 3;
			this->LabelStartTime->Text = L"Start Time";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(21, 49);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(90, 82);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// panelTimeRun
			// 
			this->panelTimeRun->Controls->Add(this->UpTimeRun);
			this->panelTimeRun->Controls->Add(this->LabelTimeRun);
			this->panelTimeRun->Controls->Add(this->pictureBox1);
			this->panelTimeRun->Location = System::Drawing::Point(3, 3);
			this->panelTimeRun->Name = L"panelTimeRun";
			this->panelTimeRun->Size = System::Drawing::Size(280, 172);
			this->panelTimeRun->TabIndex = 0;
			// 
			// UpTimeRun
			// 
			this->UpTimeRun->AutoSize = true;
			this->UpTimeRun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UpTimeRun->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpTimeRun->ForeColor = System::Drawing::SystemColors::Control;
			this->UpTimeRun->Location = System::Drawing::Point(131, 101);
			this->UpTimeRun->Name = L"UpTimeRun";
			this->UpTimeRun->Size = System::Drawing::Size(133, 30);
			this->UpTimeRun->TabIndex = 3;
			this->UpTimeRun->Text = L"UpTimeRun";
			// 
			// LabelTimeRun
			// 
			this->LabelTimeRun->AutoSize = true;
			this->LabelTimeRun->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LabelTimeRun->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelTimeRun->ForeColor = System::Drawing::SystemColors::Control;
			this->LabelTimeRun->Location = System::Drawing::Point(131, 58);
			this->LabelTimeRun->Name = L"LabelTimeRun";
			this->LabelTimeRun->Size = System::Drawing::Size(95, 30);
			this->LabelTimeRun->TabIndex = 2;
			this->LabelTimeRun->Text = L"Up time";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(23, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(90, 82);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// PageHome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->panelInfo);
			this->Name = L"PageHome";
			this->Size = System::Drawing::Size(962, 673);
			this->panelInfo->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panelTimeSet->ResumeLayout(false);
			this->panelTimeSet->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panelTimeRun->ResumeLayout(false);
			this->panelTimeRun->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StartTime_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
