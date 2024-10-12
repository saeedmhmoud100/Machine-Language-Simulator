#include <vcclr.h>
#include "GUIInstruction.h"



namespace bonusGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class MachineLanguageSimulator : public System::Windows::Forms::Form
	{
	public:
		MachineLanguageSimulator(void)
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
		~MachineLanguageSimulator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelMemory;
	private: System::Windows::Forms::Panel^ panelCPU;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label310;
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: array<System::Windows::Forms::Label^>^ memoryArray = gcnew array<System::Windows::Forms::Label^>(256);
	private: array<System::Windows::Forms::Label^>^ RegistersArray = gcnew array<System::Windows::Forms::Label^>(17);
	private: array<System::Windows::Forms::Label^>^ RegistersDataArray = gcnew array<System::Windows::Forms::Label^>(17);
	private: array<System::Windows::Forms::Label^>^ memoryArrayHeadRow = gcnew array<System::Windows::Forms::Label^>(17);
	private: array<System::Windows::Forms::Label^>^ memoryArrayHeadColumn = gcnew array<System::Windows::Forms::Label^>(17);
	private: System::Windows::Forms::Label^ labelIR;
	private: System::Windows::Forms::Label^ labelPC;
	private: System::Windows::Forms::Label^ label00;
	private: System::Windows::Forms::Label^ label0000;
	private: System::Windows::Forms::Label^ labelMemory;
	private: System::Windows::Forms::Label^ labelCPU;


	private: System::Windows::Forms::Button^ ClearCemoryButton;
	private: System::Windows::Forms::Button^ LoadDataButton;
	private: System::Windows::Forms::Button^ RunButton;
	private: System::Windows::Forms::Button^ SingleStepButton;
	private: System::Windows::Forms::Button^ HaltButton;
	private: System::Windows::Forms::Button^ StepBack = (gcnew System::Windows::Forms::Button());
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		GUIInstruction^ inst;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{

			this->panelMemory = (gcnew System::Windows::Forms::Panel());
			this->panelCPU = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panelMemory->SuspendLayout();
			this->SuspendLayout();


			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(641, 140);
			this->textBox1->TabIndex = 11;

			// 
			// textBox2
			// 
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2->Location = System::Drawing::Point(695, 53);
			this->textBox2->MaximumSize = System::Drawing::Size(102, 25);
			this->textBox2->MinimumSize = System::Drawing::Size(102, 25);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(102, 25);
			this->textBox2->TabIndex = 12;


			// label310
			// 
			this->label310 = (gcnew System::Windows::Forms::Label());
			this->label310->AutoSize = true;
			this->label310->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label310->Location = System::Drawing::Point(692, 30);
			this->label310->Name = L"label310";
			this->label310->Size = System::Drawing::Size(105, 20);
			this->label310->TabIndex = 14;
			this->label310->Text = L"counter (PC)";


			// 
			// button6
			// 
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(695, 93);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(102, 30);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Fetch";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::FetchButton_Click);
			// 
			// button6
			// 
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(695, 93);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(102, 30);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Fetch";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::FetchButton_Click);


			// 
			// panel2
			// 
			this->panelMemory->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelMemory->Location = System::Drawing::Point(273, 186);
			this->panelMemory->Name = L"panel2";
			this->panelMemory->Size = System::Drawing::Size(554, 294);
			this->panelMemory->TabIndex = 14;




			// memory lables////////////////////////////

			for (int i = 0; i < 256; i++) {
				if (i < 17) {
					// head rows and columns
					this->memoryArrayHeadRow[i] = (gcnew System::Windows::Forms::Label());
					this->memoryArrayHeadColumn[i] = (gcnew System::Windows::Forms::Label());
				}
				// memory cells
				this->memoryArray[i] = (gcnew System::Windows::Forms::Label());
			}

			// to set memoryArrayHeadColumn in the left site
			for (int i = 0; i < 16; i++)
			{

				this->memoryArrayHeadColumn[i]->AutoSize = true;
				this->memoryArrayHeadColumn[i]->Location = System::Drawing::Point(17, 28 + 16 * i);
				this->memoryArrayHeadColumn[i]->Name = "label" + i.ToString();
				this->memoryArrayHeadColumn[i]->Size = System::Drawing::Size(21, 16);
				this->memoryArrayHeadColumn[i]->TabIndex = 49;
				if (i > 9)
					this->memoryArrayHeadColumn[i]->Text = Convert::ToString(static_cast<wchar_t>('A' + i - 10));
				else
					this->memoryArrayHeadColumn[i]->Text = i.ToString();

				this->panelMemory->Controls->Add(this->memoryArrayHeadColumn[i]);

			}


			// to set memoryArrayHeadRows in the Head
			for (int i = 0; i < 17; i++)
			{

				this->memoryArrayHeadRow[i]->AutoSize = true;
				this->memoryArrayHeadRow[i]->Location = System::Drawing::Point(58 + 27 * i, 12);
				this->memoryArrayHeadRow[i]->Name = "label" + i.ToString();
				this->memoryArrayHeadRow[i]->Size = System::Drawing::Size(21, 16);
				this->memoryArrayHeadRow[i]->TabIndex = 49;

				if (i > 9)
					this->memoryArrayHeadRow[i]->Text = Convert::ToString(static_cast<wchar_t>('A' + i - 10));
				else
					this->memoryArrayHeadRow[i]->Text = i.ToString();

				this->panelMemory->Controls->Add(this->memoryArrayHeadRow[i]);

			}



			// to set memory cells which in the center
			int PointX = 56, PointY = 28;
			int indY = 0;
			for (int i = 0; i < 256; i++)
			{
				if (i % 16 == 0) {
					PointY += 16;
					PointX = 56;
					indY++;
				}

				// memory cells
				this->memoryArray[i]->AutoSize = true;
				this->memoryArray[i]->Location = System::Drawing::Point(PointX, 12 + 16 * indY);
				this->memoryArray[i]->Name = "label" + i.ToString();
				this->memoryArray[i]->Size = System::Drawing::Size(21, 16);
				this->memoryArray[i]->TabIndex = 49;
				this->memoryArray[i]->Text = "00";
				//

				this->panelMemory->Controls->Add(this->memoryArray[i]);

				PointX += 27;

			}



			////////////////////////////////////////////////////////////////////////////////

			// panelCPU
			this->panelCPU->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelCPU->Location = System::Drawing::Point(12, 186);
			this->panelCPU->Name = L"panelCPU";
			this->panelCPU->Size = System::Drawing::Size(240, 294);
			this->panelCPU->TabIndex = 5;

			for (int i = 0; i < 16; i++) {
				// registers cells
				this->RegistersArray[i] = (gcnew System::Windows::Forms::Label());
				this->RegistersDataArray[i] = (gcnew System::Windows::Forms::Label());
			}

			for (int i = 0; i < 16; i++)
			{
				this->RegistersArray[i]->AutoSize = true;
				this->RegistersArray[i]->Location = System::Drawing::Point(15, 12 + 16 * i);
				this->RegistersArray[i]->Name = "label" + i.ToString();
				this->RegistersArray[i]->Size = System::Drawing::Size(21, 16);
				this->RegistersArray[i]->TabIndex = 49;

				if (i > 9)
					this->RegistersArray[i]->Text = "R" + Convert::ToString(static_cast<wchar_t>('A' + i - 10));
				else
					this->RegistersArray[i]->Text = "R" + i.ToString();


				/// set the data of the register
				this->RegistersDataArray[i]->AutoSize = true;
				this->RegistersDataArray[i]->Location = System::Drawing::Point(56, 12 + 16 * i);
				this->RegistersDataArray[i]->Name = "label" + i.ToString();
				this->RegistersDataArray[i]->Size = System::Drawing::Size(21, 16);
				this->RegistersDataArray[i]->TabIndex = 49;
				this->RegistersDataArray[i]->Text = "00";

				this->panelCPU->Controls->Add(this->RegistersArray[i]);
				this->panelCPU->Controls->Add(this->RegistersDataArray[i]);

			}


			// label0000
			// 
			this->label0000 = (gcnew System::Windows::Forms::Label());
			this->label0000->AutoSize = true;
			this->label0000->Location = System::Drawing::Point(167, 140);
			this->label0000->Name = L"label36";
			this->label0000->Size = System::Drawing::Size(35, 16);
			this->label0000->TabIndex = 35;
			this->label0000->Text = L"0000";

			// 
			// label00
			// 
			this->label00 = (gcnew System::Windows::Forms::Label());
			this->label00->AutoSize = true;
			this->label00->Location = System::Drawing::Point(167, 108);
			this->label00->Name = L"label35";
			this->label00->Size = System::Drawing::Size(21, 16);
			this->label00->TabIndex = 34;
			this->label00->Text = L"00";

			// 
			// labelRI
			// 
			this->labelIR = (gcnew System::Windows::Forms::Label());
			this->labelIR->AutoSize = true;
			this->labelIR->Location = System::Drawing::Point(112, 140);
			this->labelIR->Name = L"label34";
			this->labelIR->Size = System::Drawing::Size(20, 16);
			this->labelIR->TabIndex = 33;
			this->labelIR->Text = L"IR";

			// 
			// labelRI
			// 
			this->labelPC = (gcnew System::Windows::Forms::Label());
			this->labelPC->AutoSize = true;
			this->labelPC->Location = System::Drawing::Point(112, 108);
			this->labelPC->Name = L"label33";
			this->labelPC->Size = System::Drawing::Size(25, 16);
			this->labelPC->TabIndex = 32;
			this->labelPC->Text = L"PC";

			panelCPU->Controls->Add(labelPC);
			panelCPU->Controls->Add(labelIR);
			panelCPU->Controls->Add(label00);
			panelCPU->Controls->Add(label0000);
			///////////////////////////////////////////////////////////////////////////

			// titles ///////////
				// 
				// label309
				// 
			this->labelMemory = (gcnew System::Windows::Forms::Label());
			this->labelMemory->AutoSize = true;
			this->labelMemory->Location = System::Drawing::Point(505, 167);
			this->labelMemory->Name = L"label309";
			this->labelMemory->Size = System::Drawing::Size(88, 16);
			this->labelMemory->TabIndex = 11;
			this->labelMemory->Text = L"Main memory";

			// 
			// label37
			// 
			this->labelCPU = (gcnew System::Windows::Forms::Label());
			this->labelCPU->AutoSize = true;
			this->labelCPU->Location = System::Drawing::Point(103, 167);
			this->labelCPU->Name = L"label37";
			this->labelCPU->Size = System::Drawing::Size(35, 16);
			this->labelCPU->TabIndex = 4;
			this->labelCPU->Text = L"CPU";

			///////////////////////////////////////////////////////////////////////////
					/// buttons
			this->ClearCemoryButton = (gcnew System::Windows::Forms::Button());
			this->LoadDataButton = (gcnew System::Windows::Forms::Button());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->SingleStepButton = (gcnew System::Windows::Forms::Button());
			this->HaltButton = (gcnew System::Windows::Forms::Button());

			//
			// ClearCemory
			//
			this->ClearCemoryButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearCemoryButton->Location = System::Drawing::Point(108, 486);
			this->ClearCemoryButton->Name = L"button1";
			this->ClearCemoryButton->Size = System::Drawing::Size(130, 39);
			this->ClearCemoryButton->TabIndex = 6;
			this->ClearCemoryButton->Text = L"Clear Memory";
			this->ClearCemoryButton->UseVisualStyleBackColor = true;
			this->ClearCemoryButton->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::ClearMemoryButton_Click);

			// 
			// LoadData
			// 
			this->LoadDataButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoadDataButton->Location = System::Drawing::Point(244, 486);
			this->LoadDataButton->Name = L"button2";
			this->LoadDataButton->Size = System::Drawing::Size(112, 39);
			this->LoadDataButton->TabIndex = 7;
			this->LoadDataButton->Text = L"Load Data";
			this->LoadDataButton->UseVisualStyleBackColor = true;
			this->LoadDataButton->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::LoadDataButton_Click);

			// 
			// StepBack
			// 
			this->StepBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StepBack->Location = System::Drawing::Point(362, 486);
			this->StepBack->Name = L"button4";
			this->StepBack->Size = System::Drawing::Size(105, 39);
			this->StepBack->TabIndex = 9;
			this->StepBack->Text = L"Step back";
			this->StepBack->UseVisualStyleBackColor = true;
			this->StepBack->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::StepBackButton_Click);
			// 
			// Run
			// 
			this->RunButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RunButton->Location = System::Drawing::Point(480, 486);
			this->RunButton->Name = L"button3";
			this->RunButton->Size = System::Drawing::Size(68, 39);
			this->RunButton->TabIndex = 8;
			this->RunButton->Text = L"Run";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::RunButton_Click);

			// 
			// SingleStep
			// 
			this->SingleStepButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SingleStepButton->Location = System::Drawing::Point(554, 486);
			this->SingleStepButton->Name = L"button4";
			this->SingleStepButton->Size = System::Drawing::Size(105, 39);
			this->SingleStepButton->TabIndex = 9;
			this->SingleStepButton->Text = L"Single Step";
			this->SingleStepButton->UseVisualStyleBackColor = true;
			this->SingleStepButton->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::SingleStepButton_Click);

			// 
			// Halt
			// 
			this->HaltButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HaltButton->Location = System::Drawing::Point(665, 486);
			this->HaltButton->Name = L"button5";
			this->HaltButton->Size = System::Drawing::Size(93, 39);
			this->HaltButton->TabIndex = 10;
			this->HaltButton->Text = L"Halt";
			this->HaltButton->UseVisualStyleBackColor = true;
			this->HaltButton->Click += gcnew System::EventHandler(this, &MachineLanguageSimulator::HaltButton_Click);


			// 
			// TestForm
			// 
			this->inst = gcnew GUIInstruction(RegistersDataArray, memoryArray, label00, label0000);
			label00->TextChanged += gcnew System::EventHandler(this, &MachineLanguageSimulator::textBox1_TextChanged);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 542);
			this->MaximumSize = System::Drawing::Size(857, 584);
			this->MinimumSize = System::Drawing::Size(857, 584);
			this->Controls->Add(this->panelMemory);
			this->Controls->Add(this->panelCPU);
			this->Controls->Add(this->labelCPU);
			this->Controls->Add(this->labelMemory);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label310);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->ClearCemoryButton);
			this->Controls->Add(this->LoadDataButton);
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->StepBack);
			this->Controls->Add(this->SingleStepButton);
			this->Controls->Add(this->HaltButton);
			this->Name = L"TestForm";
			this->Text = L"Machine Language Simulator";
			//this->Icon = gcnew System::Drawing::Icon("bom-icon.png");
			this->panelMemory->ResumeLayout(false);
			this->panelMemory->PerformLayout();
			this->panelCPU->ResumeLayout(false);
			this->panelCPU->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void FetchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->inst->setPC(this->textBox2->Text);
		this->inst->setInstructions(false);
	}

	private: System::Void RunButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// get the instruchens from the text pox			
		this->inst->setInstructions(true);
	}


	private: System::Void SingleStepButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->inst->setInstructions(false);

	}
	private: System::Void StepBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->inst->stepBack();

	}


	private: System::Void LoadDataButton_Click(System::Object^ sender, System::EventArgs^ e) {

		// get the instruchens from the text pox
		String^ s = this->textBox1->Text;

		// split the string
		array<String^>^ words = s->Split(gcnew array<wchar_t>{' ', '\n'}, StringSplitOptions::RemoveEmptyEntries);

		this->inst->fetch(words);
		this->textBox1->Text = "";
	}

	private: System::Void HaltButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void ClearMemoryButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->inst->clearData();

	}

	private: System::Void MachineLanguageSimulator::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		int intValue = Convert::ToInt32(this->label00->Text);
		String^ formattedValue = intValue.ToString("D2");
		textBox2->Text = formattedValue;
	}
#pragma endregion
	};
}
