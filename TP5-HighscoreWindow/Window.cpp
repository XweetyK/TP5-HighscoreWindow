#include<Windows.h>
#include<FL/Fl.h>
#include<FL/Fl_Window.h>
#include<FL/Fl_Button.H>
#include<FL/Fl_Input.H>
#include<FL/Fl_Box.H>
#include<scoreLib/Score.h>
#include <stdio.h>
#include <sstream>

#define TAM 5

using namespace score;
using namespace std;

ScoreManagement manager;
list<Score>::iterator p = manager.scoreList.begin();
list<Score>::iterator aux = manager.scoreList.begin();
list<Score> ScoreList;
stringstream str;

void b1_cb(Fl_Widget* o, void*) {
	system("cls");
	Fl_Input* inA = (Fl_Input*)o->parent()->child(0);
	Fl_Input* inB = (Fl_Input*)o->parent()->child(1);
	Score player;
	int auxN;
	str << inB->value();
	str >> auxN;
	str.clear();
	player.scoreName= inA->value();
	player.score = auxN;
	manager.addScore(player);
	manager.sortList();

	for (p = manager.scoreList.begin(); p != manager.scoreList.end(); p++)
	{
		cout << (*p).score << "   " << (*p).scoreName << endl;
	}
	p = aux;
}
void b2_cb(Fl_Widget* o, void*) {
	manager.clearList();
	system("cls");
}
int main()
{
	Score players[TAM];
	players[0].score = 15;
	players[0].scoreName = "Pepe";
	players[1].score = 200;
	players[1].scoreName = "Josele";
	players[2].score = 32;
	players[2].scoreName = "Miguel";
	players[3].score = 60;
	players[3].scoreName = "Carmelita";
	players[4].score = 300;
	players[4].scoreName = "Marta";

	for (int i = 0; i < TAM; i++){
		manager.addScore(players[i]);
	}

	Fl_Window* window = new Fl_Window(300, 460, "ScoreBoard");
	window->begin();
	Fl_Input* inName = new Fl_Input(60, 50, 140, 30, "Nombre");			//child 0
	Fl_Input* inScore = new Fl_Input(60, 90, 140, 30, "Score");			//child 1
	Fl_Button* b1 = new Fl_Button(10, 420, 120, 30, "Añadir Score");	//child 2
	Fl_Button* b2 = new Fl_Button(170, 420, 120, 30, "Limpiar Score");	//child 3
	Fl_Box * box = new Fl_Box(60, 130, 140, 30,"score");	//<--------No encuentro forma de mostrar los scores, pide const char*, 
															//y cada vez que intento convertir los valores de score y scoreName el 
															//programa crashea y no entiendo el porque del error
															//Tambien intenté con Fl_Text_Display y Fl_Output y el problema es el mismo
							//---------La funcionalidad de la lista y el uso de los botones puede comprobarse en 'Debug'---------
	box->box(FL_BORDER_BOX);
	window->end();
	b1->callback(b1_cb);
	b2->callback(b2_cb);
	window->show();

	return Fl::run();
}