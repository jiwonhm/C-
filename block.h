#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand
#include <ctime> // time


#define TABLE_X 20 //x-axix of tetris
#define TABLE_Y 38 //y-axix of tetris
#define LEFT 75 // <-
#define LEFT 75 // <-
#define RIGHT 77 // ->
#define UP 71 // ↑
#define DOWN 80 // ↓


namespace tetris {
	void CursorView(char show) {
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor; //CONSOLE_CURSOR_INFO 주로 커서의 가시성(bVisible)과 커서의 크기(dwSize)를 관리

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetStdHandle 내장함수: 콘솔에 적용

		ConsoleCursor.bVisible = show; //visible = 1, invisible = 0
		ConsoleCursor.dwSize = 1; // 1~100 숫자가 클 수록 커서가 더 두꺼워짐

		SetConsoleCursorInfo(hConsole, &ConsoleCursor); //내장함수: CONSOLE_CURSOR_INFO 구조체를 사용하여 커서의 상태를 설정
		//매개변수 순서 (어떤 콘솔창에 변경을 적용할지, 어떻게 변경할지 정보를 담고 있음)
	}

	void gotoxy(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

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


		//Base class of blocks
		class Block {
		protected:
			int shape[4][4][4]; //// shape[rotate][y][x]
			int x; // x-cordinate
			int y; // y-cordinate
			int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shape[3][y][x]로 4가지 상태 표현
		public:
			int getShape(int rotationCount, int y, int x) {
				return shape[rotationCount][y][x];
			}

			int getY() {
				return y;
			}

			int getX(){
				return x;
			}

			int getRotationCount() {
				return rotationCount;
			}

			void down() { //move one step down
				y++; 
			}

			void left() {
				x--;  //move one step to the left
			}
			
			void right() {
				x++; //move one step to the right
			}

			void rotate() {
				rotationCount = (rotationCount + 1) % 4; //0,1,2,3
			}
		};

		//class block1
		class Block1 : public Block {
		public:
			Block1() {
				x = TABLE_X / 2 - 3;
				y = 1;
				rotationCount = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						for (int k = 0; k < 4; k++) {
							shape[i][j][k] = block1[i][j][k];
						}
					}
				}
			}
		};

		//Class Block2
		class Block2 :public Block {
		public:
			Block2() {
				x = TABLE_X / 2 - 3;
				y = 1;
				rotationCount = 0;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; i < 4; j++) {
						for (int k = 0; k < 4; k++) {
							shape[i][j][k] = block2[i][j][k];
						}
					}
				}
			}




		};



	

}

#endif