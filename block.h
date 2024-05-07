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
		CONSOLE_CURSOR_INFO ConsoleCursor; //CONSOLE_CURSOR_INFO �ַ� Ŀ���� ���ü�(bVisible)�� Ŀ���� ũ��(dwSize)�� ����

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetStdHandle �����Լ�: �ֿܼ� ����

		ConsoleCursor.bVisible = show; //visible = 1, invisible = 0
		ConsoleCursor.dwSize = 1; // 1~100 ���ڰ� Ŭ ���� Ŀ���� �� �β�����

		SetConsoleCursorInfo(hConsole, &ConsoleCursor); //�����Լ�: CONSOLE_CURSOR_INFO ����ü�� ����Ͽ� Ŀ���� ���¸� ����
		//�Ű����� ���� (� �ܼ�â�� ������ ��������, ��� �������� ������ ��� ����)
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