#pragma once
#include"FormNiv.h"
namespace TFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormConfig
	/// </summary>
	public ref class FormConfig : public System::Windows::Forms::Form
	{
	public:
		FormConfig(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormConfig()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ NUDwHabi;
	protected:
	private: System::Windows::Forms::NumericUpDown^ NUDwTime;
	private: System::Windows::Forms::NumericUpDown^ NUDwAliad;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ NUDwAgent;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnBeginG;
	private: System::Windows::Forms::Button^ btnAtras;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	protected:

	protected:

	protected:











	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormConfig::typeid));
			this->NUDwHabi = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDwTime = (gcnew System::Windows::Forms::NumericUpDown());
			this->NUDwAliad = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->NUDwAgent = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnBeginG = (gcnew System::Windows::Forms::Button());
			this->btnAtras = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwHabi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwAliad))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwAgent))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// NUDwHabi
			// 
			this->NUDwHabi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NUDwHabi->Location = System::Drawing::Point(569, 240);
			this->NUDwHabi->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->NUDwHabi->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NUDwHabi->Name = L"NUDwHabi";
			this->NUDwHabi->Size = System::Drawing::Size(120, 30);
			this->NUDwHabi->TabIndex = 10;
			this->NUDwHabi->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			// 
			// NUDwTime
			// 
			this->NUDwTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NUDwTime->Location = System::Drawing::Point(569, 173);
			this->NUDwTime->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 240, 0, 0, 0 });
			this->NUDwTime->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->NUDwTime->Name = L"NUDwTime";
			this->NUDwTime->Size = System::Drawing::Size(120, 30);
			this->NUDwTime->TabIndex = 9;
			this->NUDwTime->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			// 
			// NUDwAliad
			// 
			this->NUDwAliad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NUDwAliad->Location = System::Drawing::Point(569, 324);
			this->NUDwAliad->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->NUDwAliad->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NUDwAliad->Name = L"NUDwAliad";
			this->NUDwAliad->Size = System::Drawing::Size(120, 30);
			this->NUDwAliad->TabIndex = 11;
			this->NUDwAliad->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(194, 409);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(284, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Numero Maximo de Agentes";
			// 
			// NUDwAgent
			// 
			this->NUDwAgent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NUDwAgent->Location = System::Drawing::Point(569, 404);
			this->NUDwAgent->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->NUDwAgent->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NUDwAgent->Name = L"NUDwAgent";
			this->NUDwAgent->Size = System::Drawing::Size(120, 30);
			this->NUDwAgent->TabIndex = 12;
			this->NUDwAgent->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(202, 329);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(276, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Numero Maximo de Aliados";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(253, 245);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Numero de Habitantes";
			// 
			// btnBeginG
			// 
			this->btnBeginG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBeginG->Location = System::Drawing::Point(796, 569);
			this->btnBeginG->Name = L"btnBeginG";
			this->btnBeginG->Size = System::Drawing::Size(306, 55);
			this->btnBeginG->TabIndex = 0;
			this->btnBeginG->Text = L"Seleccione el Nivel";
			this->btnBeginG->UseVisualStyleBackColor = true;
			this->btnBeginG->Click += gcnew System::EventHandler(this, &FormConfig::btnBeginG_Click);
			// 
			// btnAtras
			// 
			this->btnAtras->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAtras->Location = System::Drawing::Point(23, 583);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(79, 32);
			this->btnAtras->TabIndex = 14;
			this->btnAtras->Text = L"atras";
			this->btnAtras->UseVisualStyleBackColor = true;
			this->btnAtras->Click += gcnew System::EventHandler(this, &FormConfig::btnAtras_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(12, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(371, 46);
			this->label5->TabIndex = 13;
			this->label5->Text = L"CONFIGURACION";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(298, 175);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tiempo de Juego";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-37, -31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1203, 732);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// FormConfig
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->ClientSize = System::Drawing::Size(1114, 650);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnBeginG);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnAtras);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->NUDwAliad);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->NUDwAgent);
			this->Controls->Add(this->NUDwHabi);
			this->Controls->Add(this->NUDwTime);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FormConfig";
			this->Text = L"FormConfig";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwHabi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwAliad))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwAgent))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBeginG_Click(System::Object^ sender, System::EventArgs^ e) {
		FormNiv^ form = gcnew FormNiv(Convert::ToInt32(NUDwTime->Value),
		Convert::ToInt32(NUDwAliad->Value), Convert::ToInt32(NUDwHabi->Value), Convert::ToInt32(NUDwAgent->Value));
		this->Hide();
		form->ShowDialog();
		delete form;
		this->Show();
		
	}
private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
