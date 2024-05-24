#include "GameTable.h"
#include <iostream>
#include <ctime> // time
#include <cstdlib> // rand

using namespace std;

namespace tetris {
	GameTable::GameTable(int x, int y) : m_x(x), m_y(y) {
		//Initialize the table
		for (int i = 0; i < y; i++) {
			vector<int> temp;
			for (int j = 0; j < x; j++) {
				temp.push_back(0);
			}
			table.push_back(temp);
		}

		//Managing the edge of Tetris
		for (int i = 0; i < x; i++) {
			table[0][i] = 1;
			table[y - 1][i] = 1;
		}

		for (int i = 0; i < y - 1; i++) {
			table[i][0] = 1;
			table[i][x - 1] = 1;
		}

	}

	void GameTable::DrawGameTable() {
		for (int i = 0; i < m_y; i++) {
			for (int j = 0; j < m_x; j++) {
				if (table[i][j] == 1) {
					cout << "¢Ë";
				}
				else {
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}



	void GameTable::createBlock() {
		srand((unsigned int)time(NULL));
		int select = rand() % 5 + 1; //1~5 Blocks

		if (select == 1) blockObject = new TemplatedBlock<block1>();
		else if (select == 2) blockObject = new TemplatedBlock<block2>();
		else if (select == 3) blockObject = new TemplatedBlock<block3>();
		else if (select == 4) blockObject = new TemplatedBlock<block4>();
		else if (select == 5) blockObject = new TemplatedBlock<block5>();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int Y = j + blockObject->getY();
				int X = i + blockObject->getX();
				table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
			}
		}

	}


		GameTable::~GameTable() {
			delete blockObject;
		}


	}


	

