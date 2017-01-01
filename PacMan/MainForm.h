#pragma once
//#pragma execution_character_set("utf-8")
#include <iostream>
#include "Engine.h"
namespace WindowForm {


	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		bool run = true;
		bool handledArrows = false;
		Thread^ engThread;
		Thread^ winThread;
		Engine^ eng;

	public:
		MainForm(Engine %eng)
		{
			this->eng = %eng;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void setMap(String^ str) {

			this->mapArea->ResetText();
			int length = str->Length;
			if (length >= 187) {
				for (int i = 0;i < 11;i++) {
					appendToMap((str->Substring((i * 17), 17)));
					if (i != 10) {
						appendToMap("\n");
					}

				}
			}
			else
			{
				this->mapArea->Text = str;
			}
		}

		void appendToMap(String^ s)
		{
			this->mapArea->AppendText(s);
		}

		void append(String^ str)
		{
			if (this->mapArea->InvokeRequired)
			{
				cli::array<Object^>^ string = { str };
				BeginInvoke(gcnew setMapArea(this, &MainForm::setMap), string);
			}
			else
			{
				this->setMap(str);
			}

		}

		void setScore(int score)
		{
			if (this->ScoreShow->InvokeRequired)
			{
				cli::array<Object^>^ scor = {score};
				BeginInvoke(gcnew setScoreShow(this, &MainForm::writeScore), scor);
			} else
			{
				this->writeScore(score);
			}
		}

		void writeScore(int score)
		{
			this->ScoreShow->Text = ""+score;
		}


		void winLoop()
		{
			this->run = true;
			while (run)
			{
				this->append(eng->map);
				this->setScore(eng->getScore());
				_sleep(500);
			}
		}

		void stop()
		{
			this->run = false;
		}

	private:
		delegate void setMapArea(String^ s);
		delegate void setScoreShow(int in);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ mapArea;
	private: System::Windows::Forms::TextBox^ ScoreShow;


	private: System::Windows::Forms::Label^ TextScore;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menu;
	private: System::Windows::Forms::ToolStripMenuItem^ gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ level1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;


	private: System::ComponentModel::IContainer^ components;

	private:
		// <summary>
		// Required designer variable	
		// </summary>


#pragma region Windows Form Designer generated code
/// <summary>
/// Required method for Designer support - do not modify
/// the contents of this method with the code editor.
/// </summary>
		void InitializeComponent(void)
		{
			this->mapArea = (gcnew System::Windows::Forms::RichTextBox());
			this->ScoreShow = (gcnew System::Windows::Forms::TextBox());
			this->TextScore = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->level1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mapArea
			// 
			this->mapArea->Font = (gcnew System::Drawing::Font(L"Courier New", 25.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mapArea->Location = System::Drawing::Point(13, 30);
			this->mapArea->Name = L"mapArea";
			this->mapArea->ReadOnly = true;
			this->mapArea->Size = System::Drawing::Size(357, 416);
			this->mapArea->TabIndex = 0;
			this->mapArea->Text = L"PacMan\nSelect new Level";
			// 
			// ScoreShow
			// 
			this->ScoreShow->Location = System::Drawing::Point(283, 4);
			this->ScoreShow->Name = L"ScoreShow";
			this->ScoreShow->ReadOnly = true;
			this->ScoreShow->Size = System::Drawing::Size(64, 20);
			this->ScoreShow->TabIndex = 1;
			// 
			// TextScore
			// 
			this->TextScore->AutoSize = true;
			this->TextScore->Location = System::Drawing::Point(242, 7);
			this->TextScore->Name = L"TextScore";
			this->TextScore->Size = System::Drawing::Size(35, 13);
			this->TextScore->TabIndex = 2;
			this->TextScore->Text = L"Score";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->menu, this->exitToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(379, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menu
			// 
			this->menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->gameToolStripMenuItem });
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(43, 20);
			this->menu->Text = L"New";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->level1ToolStripMenuItem });
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(105, 22);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// level1ToolStripMenuItem
			// 
			this->level1ToolStripMenuItem->Name = L"level1ToolStripMenuItem";
			this->level1ToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->level1ToolStripMenuItem->Text = L"Level 1";
			this->level1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::level1ToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 458);
			this->Controls->Add(this->TextScore);
			this->Controls->Add(this->ScoreShow);
			this->Controls->Add(this->mapArea);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::MainForm_KeyPress);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void level1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//Starting the threads of Level 1
		this->eng->stop();
		this->stop();
		this->eng->setLevel(1);
		engThread = gcnew Thread(gcnew ThreadStart(this->eng, &Engine::startEngine));
		engThread->Start();
		winThread = gcnew Thread(gcnew ThreadStart(this, &WindowForm::MainForm::winLoop));
		winThread->Start();

	}
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->ActiveControl = this->TextScore;
	}



	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		this->ActiveControl = this->TextScore;
		if (this->eng->run == true) {
			this->handledArrows = false;
			switch (e->KeyCode)
			{
			case (Keys::Left):
			{
				this->eng->setCharacterMove(0);
				this->handledArrows = true;
				break;
			}
			case (Keys::Right):
			{
				this->eng->setCharacterMove(1);
				this->handledArrows = true;
				break;
			}
			case (Keys::Up):
			{
				this->eng->setCharacterMove(2);
				this->handledArrows = true;
				break;
			}
			case (Keys::Down):
			{
				this->eng->setCharacterMove(3);
				this->handledArrows = true;
				break;
			}

			}
		}
	};
	private: System::Void MainForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = handledArrows;
	}

};
}
