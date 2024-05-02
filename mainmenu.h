#ifndef MAINMENU_H
#define MAINMENU_H

#include<iostream>
#include<vector>

namespace tetris {
	class GameTable {
		int m_x;
		int m_y;
		std::vector<std::vector<int>> table; // Table 0 = " ", 1 = "в╦" , 2  = "бс"
	public:
		GameTable(int x, int y);
		void DrawGameTable();

	};


}

#endif