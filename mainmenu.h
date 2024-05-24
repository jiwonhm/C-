#ifndef MAINMENU_H
#define MAINMENU_H

#include<iostream>
#include<vector>
#include <conio.h>
#include "block.h"

#define TABLE_X 20 //x-axix of tetris
#define TABLE_Y 38 //y-axix of tetris
#define LEFT 75 // <-
#define LEFT 75 // <-
#define RIGHT 77 // ->
#define UP 71 // ↑
#define DOWN 80 // ↓

using namespace std;

namespace tetris {
	

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

	class GamePlay {
	private:
		GameTable* gt;
	public:
		GamePlay() {
			gt = new GameTable(TABLE_X, TABLE_Y); //게임 판 그리기 객체 생성
			gt->createBlock();
		}
	};

}

#endif