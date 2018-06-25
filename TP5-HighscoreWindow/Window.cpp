#include<Windows.h>
#include<FL/Fl.h>
#include<FL/Fl_Output.h>
#include<FL/Fl_Window.h>
#include<FL/Fl_Button.H>
#include<FL/Fl_Input.H>
#include<scoreLib/Score.h>
#include <stdio.h>
#include <sstream>

#define TAM 5

using namespace score;
using namespace std;

ScoreManagement manager;
list<Score>::iterator p = manager.scoreList.begin();
list<Score> ScoreList;
stringstream str;

void b1_cb(Fl_Widget* o, void*) {
	Fl_Input* inA = (Fl_Input*)o->parent()->child(0);
	Fl_Input* inB = (Fl_Input*)o->parent()->child(1);
	Fl_Output* outA = (Fl_Output*)o->parent()->child(4);
	Score player;
	int auxN;
	str << inB->value();
	str >> auxN;
	player.scoreName= inA->value();
	player.score = auxN;
	manager.addScore(player);
	manager.sortList();
	outA->value("nombre",(*p).score);
}
void b2_cb(Fl_Widget* o, void*) {
	manager.clearList();
}
int main()
{
	Fl_Window* window = new Fl_Window(300, 460, "ScoreBoard");
	window->begin();
	Fl_Input* inName = new Fl_Input(60, 50, 140, 30, "Nombre");			//child 0
	Fl_Input* inScore = new Fl_Input(60, 90, 140, 30, "Score");			//child 1
	Fl_Button* b1 = new Fl_Button(10, 420, 120, 30, "Añadir Score");	//child 2
	Fl_Button* b2 = new Fl_Button(170, 420, 120, 30, "Limpiar Score");	//child 3
	Fl_Output* outN = new Fl_Output(60, 130, 140, 30);					//child 4
	window->end();
	b1->callback(b1_cb);
	b2->callback(b2_cb);
	window->show();
	
	/*Score players[TAM];
	players[0].score = 15;
	players[0].scoreName = "Pepe";
	players[1].score = 200;
	players[1].scoreName = "Josele";
	players[2].score = 32;
	players[2].scoreName = "Miguel";
	players[3].score = 60;
	players[3].scoreName = "Carmelita";

	for (int i = 0; i < TAM; i++){
		manager.addScore(players[i]);
	}
	manager.sortList();*/

	return Fl::run();
}