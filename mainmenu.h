#ifndef MAINMENU_H
#define MAINMENU_H

#include<iostream>
#include<vector>
#include <conio.h>

using namespace std;

namespace tetris {
	class GameTable {
		int m_x;
		int m_y;
		std::vector<std::vector<int>> table; // Table 0 = " ", 1 = "в╦" , 2  = "бс"
	public:
		GameTable(int x, int y);
		void DrawGameTable();

	};

	class MainMenu {
	public:
		MainMenu() {
			cout << "\n\n\n\n";
			cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
			cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
			cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
			cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
			cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
			cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
			cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
			cout << "\t\t"; cout << "                Press any key if you want to start\n\n\n\n\n\n\n";
			cout << "\t\t"; cout << "                   TetrisGame1.0 By SeokJinLee\n";
			_getch(); //get user input
			system("cls"); //console clear
		}
	};

	class GamePlay
	//1 gameplay,  2 block roation

}

#endif