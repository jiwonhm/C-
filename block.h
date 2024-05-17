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
	void CursorView(char show);

	void gotoxy(int x, int y);

		//Block 1
		const int block1[4][4][4];

		//Block 2
		const int block2[4][4][4];

		//block 3
		const int block3[4][4][4];

		//block 4
		const int block4[4][4][4];

		//block 5
		const int block5[4][4][4];


		//Base class of blocks
		class Block {
		protected:
			int shape[4][4][4]; //// shape[rotate][y][x]
			int x; // x-cordinate
			int y; // y-cordinate
			int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shape[3][y][x]로 4가지 상태 표현
		public:
			int getShape(int rotationCount, int y, int x);

			int getY();

			int getX();

			int getRotationCount();

			void down();

			void left();
			
			void right();

			void rotate();
		};

		////class block1
		//class Block1 : public Block {
		//public:
		//	Block1() {
		//		x = TABLE_X / 2 - 3;
		//		y = 1;
		//		rotationCount = 0;
		//		for (int i = 0; i < 4; i++) {
		//			for (int j = 0; j < 4; j++) {
		//				for (int k = 0; k < 4; k++) {
		//					shape[i][j][k] = block1[i][j][k];
		//				}
		//			}
		//		}
		//	}
		//};

		////Class Block2
		//class Block2 :public Block {
		//public:
		//	Block2() {
		//		x = TABLE_X / 2 - 3;
		//		y = 1;
		//		rotationCount = 0;
		//		for (int i = 0; i < 4; i++) {
		//			for (int j = 0; i < 4; j++) {
		//				for (int k = 0; k < 4; k++) {
		//					shape[i][j][k] = block2[i][j][k];
		//				}
		//			}
		//		}
		//	}

		//};

		////class Block3
		//class Block3 : public Block {
		//public:
		//	Block3() {
		//		x = TABLE_X / 2 - 3;
		//		y = 1;
		//		rotationCount = 0;
		//		for (int i = 0; i < 4; i++) {
		//			for (int j = 0; i < 4; i++) {
		//				for (int k = 0; k < 4; k++) {
		//					shape[i][j][k] = block3[i][j][k];
		//				}
		//			}
		//		}
		//	}
		//};


		////class Block4
		//class Block4: public Block {
		//public:
		//	Block4() {
		//		x = TABLE_X / 2 - 3;
		//		y = 1;
		//		rotationCount = 0;
		//		for (int i=0; i < 4; i++) {
		//			for (int j = 0; j < 4; j++) {
		//				for (int k = 0; k < 4; k++) {
		//					shape[i][j][k] = block4[i][j][k];
		//				}
		//			}
		//		}
		//	}

		//};

		////class Block5
		//class Block5 : public Block {
		//public:
		//	Block5() {
		//		x = TABLE_X / 2 - 3;
		//		y = 1;
		//		rotationCount = 0;
		//		for (int i = 0; i < 4; i++) {
		//			for (int j = 0; j < 4; j++) {
		//				for (int k = 0; k < 4; k++) {
		//					shape[i][j][k] = block5[i][j][k];
		//				}
		//			}
		//		}
		//	}

		//};


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

#endif