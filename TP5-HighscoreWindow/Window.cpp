#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>
#include<FL/Fl_Button.H>
#include<FL/Fl_Input.H>
#include<scoreLib/Score.h>
#include <stdio.h>
#include <sstream>

#define TAM 5

using namespace score;
using namespace std;

void b1_cb(Fl_Widget* o, void*) {
	Fl_Input* inA = (Fl_Input*)o->parent()->child(0);
	Fl_Input* inB = (Fl_Input*)o->parent()->child(1);
	ScoreManagement* _manager = (ScoreManagement*)o->parent()->child(4);
	Score player;
	stringstream str;
	int auxN;
	str << inB->value();
	str >> auxN;
	player.scoreName= inA->value();
	player.score = auxN;
}
void b2_cb(Fl_Widget* o, void*) {
}
void make_Win() {
	Fl_Window* window= new Fl_Window(300, 460, "ScoreBoard");
	window->begin();
		Fl_Input* inName = new Fl_Input(60, 50, 140, 30, "Nombre");			//child 0
		Fl_Input* inScore = new Fl_Input(60, 90, 140, 30, "Score");			//child 1
		Fl_Button* b1 = new Fl_Button(10, 420, 120, 30, "Añadir Score");	//child 2
		Fl_Button* b2 = new Fl_Button(170, 420, 120, 30, "Ordenar Score");	//child 3
		ScoreManagement* manager = new ScoreManagement;						//child 4
	window->end();
	b1->callback(b1_cb);
	b2->callback(b2_cb);
	window->show();
}
int main()
{
	make_Win();
	
	
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