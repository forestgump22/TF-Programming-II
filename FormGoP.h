#pragma once

namespace TFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormGoP
	/// </summary>
	public ref class FormGoP : public System::Windows::Forms::Form
	{
	public:
		FormGoP(bool ganar)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->ganar = ganar;
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpG = gcnew Bitmap("official\\GanarPerder\\Ganar.png");
			bmpP = gcnew Bitmap("official\\GanarPerder\\Perder.png");
		
		}
	private:
		bool ganar;
		Graphics^ g;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ space;
		Bitmap^ bmpG;
	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ bmpP;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormGoP()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(929, 566);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormGoP::timer1_Tick);
			// 
			// FormGoP
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(927, 567);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"FormGoP";
			this->Text = L"FormGoP";
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(BackColor);
		if (this->ganar)
		{
			buffer->Graphics->DrawImage(bmpG, Rectangle(0, 0,
				panel1->Width, panel1->Height));
		}
		else
		{
			buffer->Graphics->DrawImage(bmpP, Rectangle(0, 0,
				panel1->Width, panel1->Height));
		}
		buffer->Render();
	}
	};
}
