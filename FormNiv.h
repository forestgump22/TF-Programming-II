#pragma once

#include"GameForm.h"
namespace TFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormNiv
	/// </summary>
	public ref class FormNiv : public System::Windows::Forms::Form
	{
	public:
		FormNiv(int a,int b,int c,int n)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->a = a;
			this->b = b;
			this->c = c;
			d = n;
			g = panel1->CreateGraphics();
			g2 = panel2->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			space2 = BufferedGraphicsManager::Current;
			buffer2 = space->Allocate(g2, panel2->ClientRectangle);

			bmpImg1 = gcnew Bitmap("official\\INiveles\\Inivel1.png");
			bmpImg2 = gcnew Bitmap("official\\INiveles\\Inivel2.png");
		}
	private:
		Graphics^ g;
		Graphics^ g2;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer2;
		BufferedGraphicsContext^ space2;
		Bitmap^ bmpImg1;
		int a, b, c, d;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
		   Bitmap^ bmpImg2;


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormNiv()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ NUDwNivel;

	private: System::Windows::Forms::Button^ btnGo;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnAtras;
	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormNiv::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NUDwNivel = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnGo = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnAtras = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwNivel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::RoyalBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Azure;
			this->label1->Location = System::Drawing::Point(474, 244);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Nivel";
			// 
			// NUDwNivel
			// 
			this->NUDwNivel->BackColor = System::Drawing::Color::White;
			this->NUDwNivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NUDwNivel->ForeColor = System::Drawing::Color::Black;
			this->NUDwNivel->Location = System::Drawing::Point(452, 276);
			this->NUDwNivel->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->NUDwNivel->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NUDwNivel->Name = L"NUDwNivel";
			this->NUDwNivel->Size = System::Drawing::Size(120, 30);
			this->NUDwNivel->TabIndex = 5;
			this->NUDwNivel->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// btnGo
			// 
			this->btnGo->BackColor = System::Drawing::Color::DodgerBlue;
			this->btnGo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGo->Location = System::Drawing::Point(897, 530);
			this->btnGo->Name = L"btnGo";
			this->btnGo->Size = System::Drawing::Size(95, 39);
			this->btnGo->TabIndex = 3;
			this->btnGo->Text = L"GO!";
			this->btnGo->UseVisualStyleBackColor = false;
			this->btnGo->Click += gcnew System::EventHandler(this, &FormNiv::btnGo_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(27, 121);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(403, 309);
			this->panel1->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(590, 121);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(427, 309);
			this->panel2->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::DarkTurquoise;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Azure;
			this->label2->Location = System::Drawing::Point(158, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 31);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nivel 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::DarkTurquoise;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Azure;
			this->label3->Location = System::Drawing::Point(786, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 31);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Nivel 2";
			// 
			// btnAtras
			// 
			this->btnAtras->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnAtras->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAtras->Location = System::Drawing::Point(27, 531);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(79, 39);
			this->btnAtras->TabIndex = 10;
			this->btnAtras->Text = L"atras";
			this->btnAtras->UseVisualStyleBackColor = false;
			this->btnAtras->Click += gcnew System::EventHandler(this, &FormNiv::btnAtras_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormNiv::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-5, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1038, 607);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Black;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(137, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 31);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Pandemia";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Black;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(698, 77);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(294, 31);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Calentamiento Global";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::SpringGreen;
			this->label6->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(12, 483);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(430, 21);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Ayuda a los infectados y protégelos de los antivacunas!";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::SpringGreen;
			this->label7->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(541, 483);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(476, 21);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Ayuda a los africanos a beber, pero cuidado con los ladrones!";
			// 
			// FormNiv
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSkyBlue;
			this->ClientSize = System::Drawing::Size(1029, 605);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnAtras);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->NUDwNivel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnGo);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FormNiv";
			this->Text = L"FormNiv";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NUDwNivel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	buffer->Graphics->DrawImage(bmpImg1,0,0, panel1->Width, panel1->Height);
	buffer2->Graphics->DrawImage(bmpImg2,0,0, panel2->Width, panel2->Height);
	buffer->Render(g);
	buffer2->Render(g2);
}
private: System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e) {
	//frmG->Show();
	GameForm^ frmG = gcnew GameForm(a,b,c,d,Convert::ToInt32(NUDwNivel->Value));
	this->Hide();
	frmG->ShowDialog();
	delete frmG;
	this->Show();
}
};
}
