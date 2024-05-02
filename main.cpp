#include <iostream>
#include <vector>
#include "mainmenu.h"



int main() {

	GameTable gt(TABLE_X, TABLE_Y); //make object
	MainMenu(); 
	gt.DrawGameTable();
	getchar();


	return 0;
}