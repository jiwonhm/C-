#include<iostream>
#include<vector>
//1.1 ������, �� ����, �� ȸ�� ����
#include<conio.h> //�ܼ� ����� ����
#include<window.h> //�ܼ� â ũ��� ����, ���� �� ���丮 �� ����
#include<cstdlib> //rand ���� ���� ��
#include<ctime> //time �ð����� �Լ� ����
using namespace std;

/*
���� = 0
�� = 1
�� = 2
*/

#define TABLE_X 20; //tetris x-axis
#define TABLE_Y 38; //tetris y-axis

#define LEFT 75 //���� ����Ű�� ��ĵ�ڵ� ��
#define RIGHT 77 //������ ����Ű�� ��ĵ�ڵ� ��
#define UP 71 //���� ����Ű�� ��ĵ�ڵ� ��
#define DOWN 80 //�Ʒ��� ����Ű�� ��ĵ�ڵ� ��

//Ŀ�� �����(0), Ŀ�� ���̱�(1)
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    //�ܼ��� �ڵ��� ������ ���� ��
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //ConsoleCursor ����ü�� ����� ����
    ConsoleCursor.bVisible = show; //Ŀ���� ���̰� ���� ������ ����
    ConsoleCursor.dwSize = 1; // Ŀ���� ũ�⸦ ����(1�� �����Ͽ� �⺻ ũ��� ����)

    //������ ������ �ֿܼ� ����
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

//�ܼ� Ŀ�� ��ġ �̵�
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
}, {
    {0,0,2,0},
    {0,0,2,0},
    {0,0,2,0},
    {0,0,2,0}
}, {
    {0,0,0,0},
    {0,0,0,0},
    {2,2,2,2},
    {0,0,0,0}
}, {
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
// Block 3
const int block3[4][4][4] ={ 
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
    {0,0,0,0},
},
{
    {0,2,2,0},
    {0,0,2,0},
    {0,0,2,0},
    {0,0,0,0}
}, {
    {0,0,0,0},
    {0,0,2,0},
    {2,2,2,0},
    {0,0,0,0}
}
};

//Block 4
const int block4[4][4][4] = {
    {
    {0,0,0,0},
    {0,2,0,0},
    {0,2,2,0},
    {0,0,2,0}
},{
    {0,0,0,0},
    {0,2,2,0},
    {2,2,0,0},
    {0,0,0,0}
},
    {
    {0,0,0,0},
    {0,2,0,0},
    {0,2,2,0},
    {0,0,2,0}
},
{
    {0,0,0,0},
    {0,2,2,0},
    {2,2,0,0},
    {0,0,0,0}
}

};

// Block 5
const int block5[4][4][4] = {
    {
    {0,0,0,0},
    {0,2,2,2},
    {0,0,2,0},
    {0,0,0,0},
},{
    {0,0,2,0},
    {0,2,2,0},
    {0,0,2,0},
    {0,0,0,0},
  },
    {
    {0,0,2,0},
    {0,2,2,2},
    {0,0,2,0},
    {0,0,0,0}
},
    {
    {0,0,2,0},
    {0,0,2,2},
    {0,0,2,0},
    {0,0,0,0}
}

};

// ���� �θ� Ŭ���� 
class Block {
protected:
    int shape[4][4][4]; //[ȸ������(rotate)][y][x] 
    int x;
    int y;
    int rotationCount; //// shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]�� 4���� ���� ǥ��

public:
    int getShape(int rotationCount, int x, int y) {
        return shape[rotationCount][y][x];
    }
    int getX() { //������ġ ��ȯ
        return x;
    }
    int getY() { //������ġ ��ȯ
        return y;
    }
    int getRotationCount() { //���� ��� ��ȯ
        return rotationCount;
    }
    void down() { //�� �� ĭ �Ʒ� �̵�
        y++;
    }
    void left() { //�� �� ĭ ���� �̵�
        x--;
    }
    void right() { //�� �� ĭ ������ �̵�
        x++; 
    }
   
    void rotate() { //�� ȸ��
        rotationCount = (rotationCount + 1) % 4; //+1�� 90�� ȸ�������� �ǹ�
    }
};

//1�� �� Ŭ����
class Block1 :public Block {
public:
    Block1() {
        x = TABLE_X / 2; //�߾� ���߱�
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

//2�� �� Ŭ����
class Block2 : public Block {
public:
    Block2() {
        x = TABLE_X / 2;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k];
                }
            }
        }
    }
};

//3�� �� Ŭ����
class Block3 : public Block {
public:
    Block3() {
        x = TABLE_X / 2;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k];
                }
            }
        }
    }
};

//4�� �� Ŭ����
class Block4 : public Block {
public:
    Block4() {
        x = TABLE_X / 2;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k];
                }
            }
        }
    }
};

//5�� �� Ŭ����
class Block5 : public Block {
public:
    Block5() {
        x = TABLE_X / 2;
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k];
                }
            }
        }
    }
};

class MainMenu {
public:
	MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
        cout << "\t\t"; cout << "                   TetrisGame1.0 By SeokJinLee\n"; //practice
        getchar(); // �ƹ�Ű �Է� ��ٸ�
        system("cls"); // �ܼ� â clear
	}
};

class GameTable {
private:
    int x; //horizonal axis
    int y; // vertical axis
    vector<vector<int>> table; // ���̺� �� 0 = " ", 1 = "��" , 2  = "��"

public:
    GameTable(int x, int y) {
        this->x = x;
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp; //y�� ��ŭ �� ����
            for (int j = 0; j < x; j++) {
                temp.push_back(0); //x���� �� ����
            }
            table.push_back(temp); //x���� ���� ä���� ���� �� �� �� �߰�
        }

        //���� �ڸ� ���� ��ĥ
        for (int i = 0; i < x; i++) { //�� ���� ��ŭ �ؾ��ϴϱ� x
            table[0][i] = 1; //������ ��
            table[y - 1][i] = 1; //������ �� �Ʒ�
        }

        for (int i = 1; i < y-1; i++) { //�̹� �� ���� �� �Ʒ� ���� ĥ�ؼ�
            table[i][0] = 1;
            table[i][x-1] = 1;
        }
    }

    void DrawGameTable() { //������ �׸����� ���
        for (int i = 0; i < y; i++) {
            for (int j = 0; i < x; j++) {
                if (table[i][j] == 1)cout << "��";
                else cout << "  "; // �� ĭ ����
            }
            cout << "\n";
            }
        }
};

//1.1 �� ���� 
void creatBlock() {

}



int main(void) {
    system("mode con cols=100 lines=40 | title tetris game"); // �ܼ�â ũ�� �� ���� ����
    GameTable gt(TABLE_X, TABLE_Y); //������ �׸��� ��ü ����
    MainMenu(); //���θ޴� �׸��� ������ ȣ��
    gt.DrawGameTable(); //������ �׸���
    getchar(); //�̰� ������ ���α׷� �ٷ� ����Ǿ, ����ڿ��� Ȯ���� �ð��� �ֱ� ����

    

    return 0;
}