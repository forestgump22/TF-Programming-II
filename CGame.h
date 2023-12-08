#pragma once
#include"CAliado.h"
#include"CEnemigo.h"
#include"CHabitante.h"
#include"CLider.h"
#include"CCreditos.h"
#include"CObjetoAlet.h"
class CGame
{
private:
	CLider* objLIDER;
	vector<CAliado*> arrAliad;
	vector<CHabitante*> arrHabi;
	vector<CEnemigo*> arrEnem;
	vector<CObjAleat*> arrobjAletG;
	vector<CObjAleat*> arrobjAletP;
	CCreditos* objcreditos;
	time_t inicio;
	time_t tenemigo;
	int tiempo;
	int puntos;
	int nAliad;
	int nEnemi;
	int nHabi;
	int numrObjAlet;
	int nivel;
	int contCambiamsj;
	int numrobjpeque, numrobjgra;
public:
	CGame(int T, int nAliad, int nHabi, int nEnem,int nivel, Graphics^ g,Rectangle^ pantalla) {
		puntos = 0;
		this->nAliad = nAliad;
		this->nEnemi = nEnem;
		this->nHabi = nHabi;
		this->tiempo = T;
		this->nivel = nivel;
		tenemigo = clock();
		inicio = clock();
		objLIDER = new CLider(g->VisibleClipBounds.Width / 2,g->VisibleClipBounds.Height / 2);
		int limx = g->VisibleClipBounds.Width;
		int limy = g->VisibleClipBounds.Height;
		for (int i = 0; i < this->nHabi; i++){
			arrHabi.push_back(new  CHabitante(rand() % (limx - 110),
				rand() % (limy - 150)+50));
		}
		objcreditos = new CCreditos(pantalla);
		contCambiamsj = 0;
		numrobjpeque = rand() % 30;
		for (int i = 0; i < numrobjpeque; i++){
			arrobjAletP.push_back(new CObjAleat(pantalla, 1));
		}
		if (this->nivel==2){
			numrobjgra = rand() % 4 + 1;
			for (int i = 0; i < numrobjgra; i++)
			{
				arrobjAletG.push_back(new CObjAleat(pantalla, 2));
			}
			for (int i = 0; i <( arrobjAletG.size()-1)&&arrobjAletG.size()>=2; i++)
			{
				for (int j = i+1; j < arrobjAletG.size(); j++)
				{
					while (arrobjAletG.at(i)->colision(arrobjAletG.at(j)->getrec()))
					{
						arrobjAletG.at(j)->reposicionar(pantalla);
					}
				}
			}
		}
		
		
	}
	~CGame() {}
	int getcontmsj() {
		contCambiamsj++;
		return contCambiamsj;
	}
	void addcruzroja(Graphics^ g) {
		if (rand() % 100 == 5) {
			for (int i = 0; i < 3; i++) {
				arrAliad.push_back(new CAliado(rand() % int(g->VisibleClipBounds.Width - 100), rand() % int(g->VisibleClipBounds.Height - 100), 2));
			}
		}
	}
	void setPuntos(int v){
		this->puntos = v;
	}
	void addAliad(){
		if (this->nAliad > 0){
			arrAliad.push_back(new CAliado(objLIDER->getX(),objLIDER->getY(),1));
			nAliad--;
		}
	}
	void addEnemi(Graphics^ g) {
		if (this->nEnemi > 0 &&(((clock() - this->tenemigo) / CLOCKS_PER_SEC)) >3)
		{
			tenemigo = clock();
			arrEnem.push_back(new CEnemigo(g->VisibleClipBounds.Width - 100,
				g->VisibleClipBounds.Height - 100));
			nEnemi--;
		}
	}
	CLider* getJugador() {
		return objLIDER;
	}
	bool continuarJuego()
	{
		if ((tiempo - (clock() - inicio) / CLOCKS_PER_SEC > 0)){
			if (puntos >= 100 || (arrAliad.size() == 0 && nAliad == 0)){
				return false;
			}
			return true;
		}
		return false;
	}
	void animacionVacuna(Graphics^ g,Bitmap^ anima,CHabitante* objhabi,CAliado* objali) {
		g->DrawImage(anima, Rectangle(objhabi->getrec().X +
			objhabi->getrec().Width / 2 - 10,
			objhabi->getrec().Y - 10, 40, 40),
			Rectangle(0, 0, anima->Width, anima->Height), GraphicsUnit::Pixel);
		g->DrawImage(anima, Rectangle(objali->getrec().X +
			objali->getrec().Width / 2 - 10,
			objali->getrec().Y - 10, 50, 50),
			Rectangle(0, 0, anima->Width, anima->Height), GraphicsUnit::Pixel);
	}
	int getScore() {
		return puntos;
	}
	/*CHabitante* CercaniaHaAlid(){
		int menorD = 20000000;
		if (arrAliad.size()>0){
			int* arr = new int[arrHabi.size()];
			for (int i = 0; i < arrHabi.size(); i++){
				arr[i] = 0;
			}
			for (int i = 0; i < arrHabi.size(); i++){
				if (arrHabi[i]->getactivo()){
					arr[i] = sqrt(pow(objLIDER->getX() - arrHabi[i]->getX(), 2) +
						pow(objLIDER->getY() - arrHabi[i]->getY(), 2));
					if (menorD > arr[i]){
						menorD = arr[i];
					}
				}
			}
			for (int i = 0; i < arrHabi.size(); i++){
				if (arrHabi[i]->getactivo()){
					if (arr[i] == menorD){
						return arrHabi[i];
					}
				}
			}
		cout << "error no encontrado habitantte mas cercano";
		}
	}*/
	//CAliado* CercaniaAgentAlid(){
	//	int menorD = 2000000000;
	//	if (arrAliad.size()>0&&arrEnem.size()>0)
	//	{
	//		int* arr = new int[arrAliad.size()];
	//		for (int i = 0; i < arrAliad.size(); i++){
	//			arr[i] = 0;
	//		}
	//		//for (int i = 0; i < arrEnem.size; i++)
	//		//{
	//		//
	//		//}
	//		for (int i = 0; i < arrAliad.size(); i++) {
	//			arr[i] = sqrt(pow(arrEnem[0]->getX() - arrAliad[i]->getX(), 2) +
	//				pow(arrEnem[0]->getY() - arrAliad[i]->getY(), 2));
	//			if (menorD > arr[i])
	//			{
	//				menorD = arr[i];
	//			}
	//		}
	//		for (int  i = 0; i < arrAliad.size(); i++)
	//		{
	//			if (arr[i] == menorD)
	//			{
	//				return arrAliad[i];
	//			}
	//		}
	//	}
	//}
	void jugar(Graphics^ g, Bitmap^ bmpLi, Bitmap^ bmpAli
		, Bitmap^ bmpEne, Bitmap^ bmpobjpeque, Bitmap^ bmpHabi, Bitmap^ bmpvacuna,
		Bitmap^ bmpcruzroja, Rectangle^ pantalla, Bitmap^ bmpobjgrande)
	{
		addEnemi(g);
		asignarcercanos();
		moveEverything( g,pantalla);
		drawEverything(g, bmpAli, bmpHabi, bmpEne, bmpLi, bmpobjpeque, bmpcruzroja,pantalla,bmpobjgrande);
		colAliadAgent();
		colHabAliad(g,bmpvacuna);
		verificaHabit();
		addcruzroja(g);
	}
	void colAliadAgent()
	{
		if (arrAliad.size() > 0 && arrEnem.size() > 0)
		{
			for (int i = 0; i < arrEnem.size(); i++)
			{
				for (int j = 0; j < arrAliad.size(); j++)
				{
					if (arrEnem.at(i)->colision(arrAliad.at(j)->getrec()))
					{
						arrAliad.erase(arrAliad.begin() + j);
						j--;
						if (puntos > 5) {
							puntos -= 5;
						}
						else {
							puntos = 0;
						}
					}
				}
			}
		}
	}
	void colHabAliad(Graphics^g,Bitmap^vacuna) {
		for (int i = 0; i < arrHabi.size(); i++){
			for (int j = 0; j < arrAliad.size(); j++){
				if (arrAliad.at(j)->colision(arrHabi.at(i)->getrec())&&
					arrHabi.at(i)->getactivo())	{
					if (arrHabi.at(i)->getresistencia() < 30) {
						animacionVacuna(g, vacuna, arrHabi.at(i), arrAliad.at(j));
						//drawimage(imagen,desttino,origen,unidad)
						//destino(x+ancho/2-10,y-10,20,20)
					}else{
						puntos += 10;
						arrHabi.at(i)->setactivo(false);
						arrHabi[i]->setTiempoProc(clock());
						arrHabi.at(i)->setresistencia();
					}
				}
			}
		}
	}
	void colLiderAgent() {
		for (int i = 0; i < arrEnem.size(); i++)
		{
			if (objLIDER->colision(arrEnem.at(i)->getfutrec()))
			{
				arrEnem.at(i)->rebote();
			}
		}
	}
	void showTimeG(Graphics^ g)	{
		g->FillRectangle(Brushes::DarkOrange, Rectangle(20, 10, 120, 20));
		g->DrawString("Tiempo: " + (tiempo - (clock() - inicio) / CLOCKS_PER_SEC).ToString(),
			gcnew Font("Arial", 14), Brushes::Black, Rectangle(20, 10, 120, 20));
	}
	void showScore(Graphics^ g)	{
		g->FillRectangle(Brushes::DarkOrange, Rectangle(170, 10, 110, 20));
		g->DrawString("Puntos: " + this->puntos.ToString(),
			gcnew Font("Arial", 14), Brushes::Black, Rectangle(170, 10, 110, 20));
	}
	void showLevel(Graphics^ g,Rectangle^ pantalla) {
		String^ mundo;
		if (nivel==1){
			mundo = gcnew String("Estadio");
			g->FillRectangle(Brushes::DarkRed, Rectangle(pantalla->Width - 250, 50, 270, 20));
			g->DrawString("Hospital de Campania", gcnew Font("Arial", 12),
				Brushes::WhiteSmoke, Rectangle(pantalla->Width - 250, 50, 270, 20));
		}
		if(nivel==2)
			mundo = gcnew String("Africa");
		if (nivel == 3)
			mundo = gcnew String("Calles");
		g->FillRectangle(Brushes::DarkRed, Rectangle(pantalla->Width - 250, 10, 270, 30));
		g->DrawString("Nivel " + nivel.ToString() + " : " + mundo, gcnew Font("Arial", 20),
			Brushes::WhiteSmoke, Rectangle(pantalla->Width - 250, 10, 270, 30));
	}
	void showInstr(Graphics^ g,Rectangle^ pantalla){
		g->FillRectangle(Brushes::DarkRed, Rectangle(20, pantalla->Height - 25, 310, 20));
		g->DrawString("Presione "+"A" +" para llamar a un Aliado", gcnew Font("Arial", 14), Brushes::WhiteSmoke,
			Rectangle(20, pantalla->Height - 25, 310, 20));
	}
	void showmensaje(Graphics^ g)
	{
		cli::array<String^>^ arrmsjActivo1 = { "Me siento mal","Me siento mareado",
		"Tengo fiebre","Me siento cansado","Tengo tos seca",
		"No tengo olfato","No respiro bien" };
		String^ msjNoActi = gcnew String("Muchas Gracias");
		cli::array<String^>^ arrmsjActivo2 = { "Tengo sed","Necesito beber","Necesito agua",
		"Denme agua porfa","Tengo fatiga","     ????    ","Tengo calambre" };
		cli::array<String^>^ arrmsjActivo3 = { "No me sientoBien","Me discriminan","Soy morena",
		"Odio ser morena","No soy blanca","quiero ser blanca","Detesto mi piel" };
		if (getcontmsj()>200){
			contCambiamsj = 0;
			for (int i = 0; i < arrHabi.size(); i++)
			{
				arrHabi.at(i)->setcontmsj(rand() % 7);
			}
		}
		for (int i = 0; i < arrHabi.size(); i++)
		{
			g->FillRectangle(Brushes::DarkRed, Rectangle(arrHabi.at(i)->getrec().X -
				arrHabi.at(i)->getrec().Width / 2, arrHabi.at(i)->getrec().Y - 15, 150, 20));
			if (arrHabi.at(i)->getactivo())
			{
				if (nivel==1)
				{
					g->DrawString(arrmsjActivo1[arrHabi.at(i)->getitmsj()], gcnew Font("Arial", 12),
						Brushes::WhiteSmoke, Rectangle(arrHabi.at(i)->getrec().X -
							arrHabi.at(i)->getrec().Width / 2, arrHabi.at(i)->getrec().Y - 15, 150, 20));
				}
				if (nivel == 2)
				{
					g->DrawString(arrmsjActivo2[arrHabi.at(i)->getitmsj()], gcnew Font("Arial", 12),
						Brushes::WhiteSmoke, Rectangle(arrHabi.at(i)->getrec().X -
							arrHabi.at(i)->getrec().Width / 2, arrHabi.at(i)->getrec().Y - 15, 150, 20));
				}
				if (nivel == 3)
				{
					g->DrawString(arrmsjActivo3[arrHabi.at(i)->getitmsj()], gcnew Font("Arial", 12),
						Brushes::WhiteSmoke, Rectangle(arrHabi.at(i)->getrec().X -
							arrHabi.at(i)->getrec().Width / 2, arrHabi.at(i)->getrec().Y - 15, 150, 20));
				}

			}else{
				g->DrawString(msjNoActi, gcnew Font("Arial", 12),
					Brushes::WhiteSmoke, Rectangle(arrHabi.at(i)->getrec().X -
						arrHabi.at(i)->getrec().Width / 2, arrHabi.at(i)->getrec().Y - 15, 150, 20));
			}
			
		}
	}
	void showCruzRoja(Graphics^g,Rectangle^ pantallla) {
		for (int i = 0; i < arrAliad.size(); i++)
		{
			if (arrAliad.at(i)->gettipo()==2)
			{
				if (nivel == 3)
				{
					g->FillRectangle(Brushes::Red, Rectangle(pantallla->Width - 500, pantallla->Height - 50, 500, 25));
					g->DrawString("Personas extra de las calles te ayudaran.....que suerte tienes :D",
						gcnew Font("Arial", 12), Brushes::GhostWhite, Rectangle(pantallla->Width - 500, pantallla->Height - 50, 500, 25));
				}
				else
				{
					g->FillRectangle(Brushes::Red, Rectangle(pantallla->Width - 500, pantallla->Height - 50, 500, 25));
					g->DrawString("La Cruz Roja Internacional te ayudara ..... que suerte tienes :D",
						gcnew Font("Arial", 12), Brushes::GhostWhite, Rectangle(pantallla->Width - 500, pantallla->Height - 50, 500, 25));
				}
			}
		}
	}
	void showNumbAEH(Graphics^ g) {
		g->FillRectangle(Brushes::DarkOrange, Rectangle(300, 10, 600, 20));
		String^ strAliados;	String^ strAgentes;	String^ strHabitantes;
		if (nivel==1){
			 strAliados = gcnew String("Enfermeros Restantes: ");
			 strAgentes = gcnew String("   Antivacunas Restantes: ");
			 strHabitantes = gcnew String("   Pacientes: ");
		}
		if (nivel == 2) 
		{
			strAliados = gcnew String("Ayudantes ONG Restantes: ");
			strAgentes = gcnew String("   Ladrones Restantes: ");
			strHabitantes = gcnew String("   Africanos: ");
		}
		if (nivel == 3)
		{
			strAliados = gcnew String("Personas Buenas: ");
			strAgentes = gcnew String("   Discriminadoras: ");
			strHabitantes = gcnew String("   Discriminadas: ");
		}
		g->DrawString(strAliados+ this->nAliad +strAgentes + this->nEnemi +strHabitantes + this->nHabi,
			gcnew Font("Arial", 14), Brushes::Black, Rectangle(300, 10, 600, 20));
	}
	int gethabacttivos(){
		int cont = 0;
		for (int i = 0; i < arrHabi.size(); i++){
			if (arrHabi.at(i)->getactivo())	cont++;
		}
		return cont;
	}
	void moveEverything( Graphics^ g,Rectangle^pantalla) {
		for (int i = 0; i < arrAliad.size(); i++){
			if (gethabacttivos()>0){
				arrAliad[i]->perseguir(arrHabi.at(arrAliad.at(i)->getcercano()), g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
				arrAliad[i]->mover(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
			}
			else{
				arrAliad.at(i)->setpositionNormal();
			}
		}
		for (int i = 0; i < arrEnem.size(); i++){
			if (arrAliad.size()){
				arrEnem.at(i)->perseguir(arrAliad.at(arrEnem.at(i)->getcercano()), g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
				colLiderAgent();
				arrEnem[i]->mover(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
			}else{
				arrEnem.at(i)->setpositionNormal();
			}
		}
		if (nivel==2){
			for (int i = 0; i < arrHabi.size(); i++){
				arrHabi.at(i)->setdx(rand() % 2 * (-10) + 5);
				arrHabi.at(i)->setdy(rand() % 2 * (-10) + 5);
				//if (!arrHabi.at(i)->colision(Rectangle(pantalla->X,pantalla->Y,pantalla->Width,pantalla->Height))) 
				{
				arrHabi.at(i)->mover(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
				}
			}
		}
		objLIDER->mover(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		
	}
	void drawEverything(Graphics^ g, Bitmap^ imgAliad, Bitmap^ imgHabi, Bitmap^ imgEnem, 
		Bitmap^ imgLider, Bitmap^ bmpobjpeque, Bitmap^ imgcruzroja,Rectangle^ pantalla,Bitmap^ bmpobjgrande) {
		showScene( bmpobjpeque,  g,  pantalla,  bmpobjgrande);
		for (int i = 0; i < arrAliad.size(); i++)
		{
			if (arrAliad.at(i)->gettipo() == 1) {
			arrAliad.at(i)->dibujar(g, imgAliad);
			}
			if (arrAliad.at(i)->gettipo() == 2) {
				arrAliad.at(i)->dibujar(g, imgcruzroja);
			}
		}
		for (int i = 0; i < arrEnem.size(); i++)
		{
			arrEnem.at(i)->dibujar(g, imgEnem);
		}
		for (int i = 0; i < arrHabi.size(); i++)
		{
			arrHabi[i]->dibujar(g, imgHabi);
		}
		objLIDER->dibujar(g, imgLider);
		showTimeG(g);
		showScore(g);
		showNumbAEH(g);
		showInstr(g, pantalla);
		showLevel(g, pantalla);
		showmensaje(g);
		showCruzRoja(g, pantalla);
	}
	void showScene(Bitmap^ bmpobjpeque,Graphics^ g,Rectangle^ pantalla,Bitmap^ bmpobjgrande)
	{
		for (int i = 0; i < arrobjAletP.size(); i++)
		{
			arrobjAletP[i]->dibujarObjAlet(g, bmpobjpeque);
		}
		for (int i = 0; i < arrobjAletG.size(); i++)
		{
			arrobjAletG[i]->dibujarObjAlet(g, bmpobjgrande);
		}
	}
	void verificaHabit() {
		for (int i = 0; i < arrHabi.size(); i++)
		{
			if (arrHabi.at(i)->getactivo())
			{
				return;
			}
			else {
				if ((clock() - arrHabi[i]->getTProceso()) / CLOCKS_PER_SEC > 30)
				{
					arrHabi.at(i)->setactivo(true);
					arrHabi.at(i)->setTiempoProc(0);
				}
			}
		}
	}
	void asignarcercanos() {
		inicializarcercano();
		for (int i = 0; i < arrAliad.size(); i++){
			for (int j = 0; j < arrHabi.size(); j++){
				if (arrHabi[j]->getactivo())
				{
					if (arrAliad.at(i)->getdist(arrHabi.at(j)) <=
						arrAliad.at(i)->getdist(arrHabi.at(arrAliad[i]->getcercano())))
					{
						arrAliad.at(i)->setcercano(j);
					}
				}
			}
		}

		for (int i = 0; i < arrEnem.size(); i++) {
			for (int j = 0; j < arrAliad.size(); j++) {
				if (arrEnem.at(i)->getdist(arrAliad.at(j)) <=
					arrEnem.at(i)->getdist(arrAliad.at(arrEnem[i]->getcercano()))){
					arrEnem.at(i)->setcercano(j);

				}
			}
		}
	}
	void inicializarcercano() {
		for (int i = 0; i < arrAliad.size(); i++) {
			for (int j = 0; j < arrHabi.size(); j++) {
				if (arrHabi[j]->getactivo()){
					arrAliad[i]->setcercano(j);
				}
			}
		}

		for (int i = 0; i < arrEnem.size(); i++)
		{
			for (int j = 0; j < arrAliad.size(); j++)
			{
				arrEnem.at(i)->setcercano(j);
			}
		}
	}
	void moverYmostrarCreditos(Graphics^ g, Bitmap^ bmpcreditos) {
		objcreditos->movercreditos(bmpcreditos);
		objcreditos->dibujarcreditos(g, bmpcreditos);
	}
};

