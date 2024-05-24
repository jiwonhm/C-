#pragma once


//#include <iostream>
//#include <vector>
//#include <conio.h>
//#include <windows.h>
//#include <cstdlib> // rand
//#include <ctime> // time
#include "block.h"


namespace tetris {
	//void CursorView(char show) {
	//	HANDLE hConsole;
	//	CONSOLE_CURSOR_INFO ConsoleCursor; //CONSOLE_CURSOR_INFO 주로 커서의 가시성(bVisible)과 커서의 크기(dwSize)를 관리

	//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetStdHandle 내장함수: 콘솔에 적용

	//	ConsoleCursor.bVisible = show; //visible = 1, invisible = 0
	//	ConsoleCursor.dwSize = 1; // 1~100 숫자가 클 수록 커서가 더 두꺼워짐

	//	SetConsoleCursorInfo(hConsole, &ConsoleCursor); //내장함수: CONSOLE_CURSOR_INFO 구조체를 사용하여 커서의 상태를 설정
	//	//매개변수 순서 (어떤 콘솔창에 변경을 적용할지, 어떻게 변경할지 정보를 담고 있음)
	//}

	//void gotoxy(int x, int y) {
	//	COORD pos = { x,y };
	//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	//}

	//Block 1
	const int block1[4][4][4] = {
		{
			{0,0,0,0},
			{0,0,0,0},
			{2,2,2,2},
			{0,0,0,0}
		},
		{
			{0,0,2,0},
			{0,0,2,0},
			{0,0,2,0},
			{0,0,2,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{2,2,2,2},
			{0,0,0,0}
		},
		{
			{0,0,2,0},
			{0,0,2,0},
			{0,0,2,0},
			{0,0,2,0}

		}

	};

	//Block 2
	const int block2[4][4][4] = {
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,2,2,0},
			{0,2,2,0},
			{0,0,0,0}
		}

	};

	//block 3
	const int block3[4][4][4] = {
		{
			{0,0,0,0},
			{0,2,0,0},
			{0,2,2,0},
			{0,0,2,0}

		},

		{	{0,0,0,0},
			{0,2,2,0},
			{2,2,0,0},
			{0,0,0,0}
		},

		{	{0,0,0,0},
			{0,2,0,0},
			{0,2,2,0},
			{0,0,2,0}
		},

		{	{0,0,0,0},
			{0,2,2,0},
			{2,2,0,0},
			{0,0,0,0}
		}

	};

	//block 4
	const int block4[4][4][4] = {
		{
			{0,2,0,0},
			{0,2,0,0},
			{0,2,2,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,2,2,2},
			{0,2,0,0},
			{0,0,0,0}
		},
		{
			{0,2,2,0},
			{0,0,2,0},
			{0,0,2,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,2,0},
			{2,2,2,0},
			{0,0,0,0}
		}

	};

	//block 5
	const int block5[4][4][4] = {
		{
			{0,0,0,0},
			{0,2,2,2},
			{0,0,2,0},
			{0,0,0,0}
		},
		{
			{0,0,2,0},
			{0,2,2,0},
			{0,0,2,0},
			{0,0,0,0}
		},
		{
			{0,0,2,0},
			{0,2,2,2},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,2,0},
			{0,0,2,2},
			{0,0,2,0},
			{0,0,0,0}
		}
	};


	
		int Block::getShape(int rotationCount, int y, int x) {
			return shape[rotationCount][y][x];
		}

		int Block::getY() {
			return y;
		}

		int Block::getX() {
			return x;
		}

		int Block::getRotationCount() {
			return rotationCount;
		}

		void Block::down() { //move one step down
			y++;
		}

		void Block::left() {
			x--;  //move one step to the left
		}

		void Block::right() {
			x++; //move one step to the right
		}

		void Block::rotate() {
			rotationCount = (rotationCount + 1) % 4; //0,1,2,3
		}



	template<const int block[4][4][4]>
	class TemplatedBlock : public Block {
	public:
		TemplatedBlock() {
			x = TABLE_X / 2 - 3;
			y = 1;
			rotationCount = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						shape[i][j][k] = block[i][j][k];
					}
				}
			}

		}
	};


	

	}






