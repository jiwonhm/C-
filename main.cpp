#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand
#include <ctime> // time
#include "mainmenu.h"
#include "block.h"

#define TABLE_X 20 //x-axix of tetris
#define TABLE_Y 38 //y-axix of tetris
#define LEFT 75 // <-
#define LEFT 75 // <-
#define RIGHT 77 // ->
#define UP 71 // ก่
#define DOWN 80 // ก้

using namespace std;
using namespace tetris;

int main() {

	MainMenu start; //game start interface

	GameTable gt(TABLE_X, TABLE_Y); //make object
	MainMenu(); 
	gt.DrawGameTable();
	_getch();


	return 0;
}