#pragma once
#include"CGame.h"
#include"FormGoP.h"
namespace TFINAL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(int tiempo,int nAli,int nHab,int nEnem,int sele)
		{
			srand(time(0));
			InitializeComponent();
			 nivel=sele;
			g = panel->CreateGraphics();
			objGame = new CGame(tiempo, nAli, nHab, nEnem,sele, g,panel->ClientRectangle);
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel->ClientRectangle);
			bmpMap = gcnew Bitmap("official\\nivel"+sele.ToString()+
				"\\fondo"+sele.ToString()+".png");
			bmpLid = gcnew Bitmap("official\\nivel" + sele.ToString() + 
				"\\lider" + sele.ToString() + ".png");
			bmpLid->MakeTransparent(bmpLid->GetPixel(1, 1));
			bmpEnem = gcnew Bitmap("official\\nivel" + sele.ToString() + 
				"\\agente" + sele.ToString() + ".png");
			bmpEnem->MakeTransparent(bmpEnem->GetPixel(1, 1));
			bmpHabit = gcnew Bitmap("official\\nivel" + sele.ToString() + 
				"\\habitante" + sele.ToString() + ".png");
			bmpHabit->MakeTransparent(bmpHabit->GetPixel(1, 1));
			bmpAlia = gcnew Bitmap("official\\nivel" + sele.ToString() + 
				"\\aliado" + sele.ToString() + ".png");
			bmpAlia->MakeTransparent(bmpAlia->GetPixel(1, 1));
			bmpObjPeque = gcnew Bitmap("official\\nivel" + sele.ToString() 
				+ "\\objPeque"+ sele.ToString() + "5" + ".png");
			bmpObjPeque->MakeTransparent(bmpObjPeque->GetPixel(1, 1));
			//obj grande
			bmpObjGrande = gcnew Bitmap("official\\nivel2\\objGrande.png");
			bmpObjGrande->MakeTransparent(bmpObjGrande->GetPixel(1, 1));
			//ayuda cruz roja
			bmpAyuda = gcnew Bitmap("official\\nivel"+sele.ToString()
				+"\\ayuda"+sele.ToString()+".png");
			bmpAyuda->MakeTransparent(bmpAyuda->GetPixel(1, 1));
			bmpcruzroja = gcnew Bitmap("official\\nivel"+sele.ToString()
				+"\\cruzroja"+sele.ToString()+".png");
			bmpcruzroja->MakeTransparent(bmpcruzroja->GetPixel(1, 1));
			bmpcreditos = gcnew Bitmap("official\\creditos\\creditos.png");
		}
	private:
		CGame* objGame;
		Graphics^ g;
		int nivel;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpMap;
		Bitmap^ bmpLid;
		Bitmap^ bmpEnem;
		Bitmap^ bmpHabit;
		Bitmap^ bmpAlia;
		Bitmap^ bmpObjPeque;
		Bitmap^ bmpObjGrande;

		Bitmap^ bmpAyuda;
		Bitmap^ bmpcruzroja;
		Bitmap^ bmpcreditos;
		
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer1;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel
			// 
			this->panel->Location = System::Drawing::Point(0, -1);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(1233, 655);
			this->panel->TabIndex = 0;
			this->panel->ClientSizeChanged += gcnew System::EventHandler(this, &GameForm::panel_ClientSizeChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &GameForm::timer2_Tick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 652);
			this->Controls->Add(this->panel);
			this->Name = L"GameForm";
			this->Text = L"Juego";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);

		buffer->Graphics->DrawImage(bmpMap,
			Rectangle(0, 0, panel->Width, panel->Height));
		
		if (objGame->continuarJuego())
		{
			objGame->jugar(buffer->Graphics,bmpLid,bmpAlia,bmpEnem, bmpObjPeque,bmpHabit,
				bmpAyuda,bmpcruzroja,panel->ClientRectangle,bmpObjGrande);
			
		}else{
			timer1->Enabled = false;
			if (objGame->getScore()>=100){
				//imprimir banner ganaste  "TAMPOCO NO TE CREAS!!! :V"
				FormGoP^ formGoP = gcnew FormGoP(true);
				this->Hide();
				formGoP->ShowDialog();
				formGoP->Close();
			}else{
				//imprimir banner perdiste "PERDISTE que NOOB!!! :V"
				FormGoP^ formGoP = gcnew FormGoP(false);
				this->Hide();
				formGoP->ShowDialog();
				formGoP->Close();
			}
			this->Show();
			//return;
			//imprimir creditos :3 con timer 2
			timer2->Enabled = true;
			//_sleep(100);
			//return;
		}
		buffer->Render(g);
	}
	private: System::Void panel_ClientSizeChanged(System::Object^ sender, System::EventArgs^ e) {
		delete buffer;
		delete g;
		g = panel->CreateGraphics();
		buffer = BufferedGraphicsManager::Current->Allocate(g, panel->ClientRectangle);
	}
	private: System::Void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up:objGame->getJugador()->setdy(-10); break;
		case Keys::Down:objGame->getJugador()->setdy(+10); break;
		case Keys::Left:objGame->getJugador()->setdx(-10); break;
		case Keys::Right:objGame->getJugador()->setdx(+10); break;
		case Keys::A: objGame->addAliad(); break;
		//case Keys::P: objGame->setPuntos(100); break;
		default:break;
		}
	}
	private: System::Void GameForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objGame->getJugador()->setdx(0);
		objGame->getJugador()->setdy(0);
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	buffer->Graphics->Clear(Color::WhiteSmoke);
	objGame->moverYmostrarCreditos(buffer->Graphics, bmpcreditos);
	buffer->Render(g);
}
};
}
