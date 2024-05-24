#pragma once
#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <vector>
#include "block.h"

namespace tetris {
	class GameTable {
		int m_x;
		int m_y;
		std::vector<std::vector<int>> table; // Table 0 = " ", 1 = "▦" , 2  = "■"
		Block* blockObject;
	public:
		GameTable(int x, int y); //테트리스 판 뼈대 생성
		void DrawGameTable(); //게임판 그리는 함수
		void createBlock();//블럭생성
		void MoveBlock(int key);//블럭이동
		void RotateBlock(); //블럭회전
		~GameTable();

	};




}

#endif