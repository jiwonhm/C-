#include <iostream>
#include <vector>
#include "mainmenu.h"

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
	
	void GameTable:: DrawGameTable() {
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
}