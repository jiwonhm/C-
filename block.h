#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand
#include <ctime> // time

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
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

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
	}



}

#endif