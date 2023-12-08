#pragma once
#include"FormInstrc.h"
#include"FormConfig.h"
#include"FormCreditos.h"
namespace TFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormPresentation
	/// </summary>
	public ref class FormPresentation : public System::Windows::Forms::Form
	{
	public:
		FormPresentation(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpPresent = gcnew Bitmap("official\\IPresentacion\\Ipresentacion.png");
		}
	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Button^ btnConfig;
	private: System::Windows::Forms::Button^ btnCreditos;


		Bitmap^ bmpPresent;

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormPresentation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Button^ btnInstruc;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::Windows::Forms::Timer^ timer1;
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->btnInstruc = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnConfig = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			timer1->Enabled = true;
			timer1->Tick += gcnew System::EventHandler(this, &FormPresentation::timer1_Tick);
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->BackColor = System::Drawing::SystemColors::HotTrack;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"MV Boli", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblBienvenida->Location = System::Drawing::Point(174, 10);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(665, 87);
			this->lblBienvenida->TabIndex = 0;
			this->lblBienvenida->Text = L"Bienvenido al Juego";
			// 
			// btnInstruc
			// 
			this->btnInstruc->Font = (gcnew System::Drawing::Font(L"MV Boli", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstruc->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnInstruc->Location = System::Drawing::Point(382, 414);
			this->btnInstruc->Name = L"btnInstruc";
			this->btnInstruc->Size = System::Drawing::Size(281, 75);
			this->btnInstruc->TabIndex = 1;
			this->btnInstruc->Text = L"Instrucciones";
			this->btnInstruc->UseVisualStyleBackColor = true;
			this->btnInstruc->Click += gcnew System::EventHandler(this, &FormPresentation::btnInstruc_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnCreditos);
			this->panel1->Controls->Add(this->btnConfig);
			this->panel1->Controls->Add(this->lblBienvenida);
			this->panel1->Controls->Add(this->btnInstruc);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1024, 585);
			this->panel1->TabIndex = 2;
			// 
			// btnConfig
			// 
			this->btnConfig->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfig->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnConfig->Location = System::Drawing::Point(271, 350);
			this->btnConfig->Name = L"btnConfig";
			this->btnConfig->Size = System::Drawing::Size(488, 43);
			this->btnConfig->TabIndex = 2;
			this->btnConfig->Text = L"Configura y Juega A Tú Manera";
			this->btnConfig->UseVisualStyleBackColor = true;
			this->btnConfig->Click += gcnew System::EventHandler(this, &FormPresentation::btnConfig_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"MV Boli", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnCreditos->Location = System::Drawing::Point(12, 516);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(198, 57);
			this->btnCreditos->TabIndex = 3;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FormPresentation::button1_Click);
			// 
			// FormPresentation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 584);
			this->Controls->Add(this->panel1);
			this->Name = L"FormPresentation";
			this->Text = L"Presentacion";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(BackColor);
		buffer->Graphics->DrawImage(bmpPresent, 0, 0, panel1->Width, panel1->Height);
		buffer->Render(g);
}
private: System::Void btnInstruc_Click(System::Object^ sender, System::EventArgs^ e) {
	FormInstrc^ formIn = gcnew FormInstrc();
	this->Hide();
	formIn->ShowDialog();
	delete formIn;
	this->Show();
}
private: System::Void btnConfig_Click(System::Object^ sender, System::EventArgs^ e) {
	FormConfig^ formConfg = gcnew FormConfig();
	this->Hide();
	formConfg->ShowDialog();
	delete formConfg;
	this->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	FormCreditos^ formCre = gcnew FormCreditos();
	this->Hide();
	formCre->ShowDialog();
	this->Show();
	delete formCre;
}
};
}

