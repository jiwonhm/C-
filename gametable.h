#pragma once
#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <vector>
#include "block.h"

namespace tetris {
	class GameTable {
		int m_x;
		int m_y;
		std::vector<std::vector<int>> table; // Table 0 = " ", 1 = "��" , 2  = "��"
		Block* blockObject;
	public:
		GameTable(int x, int y); //��Ʈ���� �� ���� ����
		void DrawGameTable(); //������ �׸��� �Լ�
		void createBlock();//������
		void MoveBlock(int key);//���̵�
		void RotateBlock(); //��ȸ��
		~GameTable();

	};




}

#endif