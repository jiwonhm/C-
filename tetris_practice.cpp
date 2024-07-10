#include <iostream>
#include <vector>
#include <conio.h> // 콘솔 입출력 위해
#include <windows.h> // 콘솔 창 크기와 색상, 파일 및 디렉토리 등 관리
#include <cstdlib> // rand 난수 생성 등
#include <ctime> // time 시간 관련 함수 제공
using namespace std;

/*
공백 = 0
▦ = 1
■ = 2
*/

#define TABLE_X 20 // tetris x-axis
#define TABLE_Y 38 // tetris y-axis

#define LEFT 75 // 왼쪽 방향키의 스캔코드 값
#define RIGHT 77 // 오른쪽 방향키의 스캔코드 값
#define UP 71 // 위쪽 방향키의 스캔코드 값
#define DOWN 80 // 아래쪽 방향키의 스캔코드 값

// 커서 숨기기(0), 커서 보이기(1)
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    // 콘솔의 핸들을 가지고 오는 것
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // ConsoleCursor 구조체의 멤버를 설정
    ConsoleCursor.bVisible = show; // 커서를 보이게 할지 숨길지 설정
    ConsoleCursor.dwSize = 1; // 커서의 크기를 설정(1로 설정하여 기본 크기로 유지)

    // 설정한 정보를 콘솔에 적용
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

// 콘솔 커서 위치 이동
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Block 1
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

// Block 2
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
const int block3[4][4][4] = {
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

// Block 4
const int block4[4][4][4] = {
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

// 블럭의 부모 클래스 
class Block {
protected:
    int shape[4][4][4]; //[회전상태(rotate)][y][x] 
    int x;
    int y;
    int rotationCount; //// shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]로 4가지 상태 표현

public:
    int getShape(int rotationCount, int x, int y) {
        return shape[rotationCount][y][x];
    }
    int getX() { //현재위치 반환
        return x;
    }
    int getY() { //현재위치 반환
        return y;
    }
    int getRotationCount() { //현재 모양 반환
        return rotationCount;
    }
    void down() { //블럭 한 칸 아래 이동
        y++;
    }
    void left() { //블럭 한 칸 왼쪽 이동
        x--;
    }
    void right() { //블럭 한 칸 오른쪽 이동
        x++;
    }

    void rotate() { //블럭 회전
        rotationCount = (rotationCount + 1) % 4; //+1은 90도 회전했음을 의미
    }
};

// 1번 블럭 클래스
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2; // 중앙 맞추기
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

// 2번 블럭 클래스
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

// 3번 블럭 클래스
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

// 4번 블럭 클래스
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

// 5번 블럭 클래스
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
        cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
        cout << "\t\t"; cout << "                   TetrisGame1.0 By SeokJinLee\n"; //practice
        getchar(); // 아무키 입력 기다림
        system("cls"); // 콘솔 창 clear
    }
};

class GameTable {
private:
    int x; // horizontal axis
    int y; // vertical axis
    Block* blockObject;
    vector<vector<int>> table; // 테이블 판 0 = " ", 1 = "▦", 2 = "■"

public:
    GameTable(int x, int y) {
        this->x = x;
        this->y = y;
        blockObject = nullptr;
        for (int i = 0; i < y; i++) {
            vector<int> temp; // y개 만큼 행 생성
            for (int j = 0; j < x; j++) {
                temp.push_back(0); // x개의 열 생성
            }
            table.push_back(temp); // x개의 열로 채워진 행을 한 줄 씩 추가
        }

        // 가장자리 뼈대 색칠
        for (int i = 0; i < x; i++) { // 열 갯수 만큼 해야 하니까 x
            table[0][i] = 1; // 가로축 위
            table[y - 1][i] = 1; // 가로축 맨 아래
        }

        for (int i = 1; i < y - 1; i++) { // 이미 맨 위와 맨 아래 행을 칠해서
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }

    void DrawGameTable() { // 게임판 그림으로 출력
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1) cout << "▦";
                else if (table[i][j] == 2) cout << "■";
                else cout << "  "; // 두 칸 띄우기
            }
            cout << "\n";
        }
    }

    // 블럭 생성 함수
    void createBlock() {
        srand((unsigned int)time(NULL)); // 난수 시드 생성
        int select = rand() % 5 + 1; // 난수를 통해 1~5 블럭
        if (select == 1) {
            blockObject = new Block1();
        }
        else if (select == 2) {
            blockObject = new Block2();
        }
        else if (select == 3) {
            blockObject = new Block3();
        }
        else if (select == 4) {
            blockObject = new Block4();
        }
        else if (select == 5) {
            blockObject = new Block5();
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = i + blockObject->getY();
                int X = j + blockObject->getX();
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j); // 블록 객체의 현재 회전 상태에서 i, j 위치 가져오는 것
            }
        }
    }

    // 블럭 이동 함수
    void MoveBlock(int key) { // 테이블에서 블럭 객체 지우기
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = i + blockObject->getY();
                int X = j + blockObject->getX();
                if (table[Y][X] == 2) { // 만약 블럭이면
                    table[Y][X] = 0; // 테이블에서 지운다
                }
            }
        }
        if (key == DOWN) {
            blockObject->down();
        }
        else if (key == LEFT) {
            blockObject->left();
        }
        else if (key == RIGHT) {
            blockObject->right();
        }

        // 이동한 블럭 상태 테이블에 갱신
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = i + blockObject->getY();
                int X = j + blockObject->getX();
                if (table[Y][X] == 0) {
                    table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                }
            }
        }
    }
};

// 게임 시작 클래스
class GamePlay {
private:
    GameTable* gt;
public:
    GamePlay() {
        gt = new GameTable(TABLE_X, TABLE_Y);//게임 판 그리는 객체 생성
        gt->creatBlock();//초기 블럭 생성
        gt->DrawGameTable(); //게임판을 그림
        while (true) { //방향키 입력 이벤트, 무한 루프
            int nSelect;
            if (_kbhit()) { //키보드 입력이 있는지 확인
                nSelect = _getch();
                if (nSelect == 224) {
                    nSelect = _getch();
                    switch (nSelect) {
                    case UP: // 화살표 위 눌렀을 때
                        gt->RotateBlock(); // 블럭을 90도 회전 
                        gotoxy(0, 0); //system("cls") 안쓰고 (0, 0)으로 커서 이동 후
                        gt->DrawGameTable(); // 덮어쓰기 
                        break;
                    case DOWN: // 화살표 아래 눌렀을 때
                        gt->MoveBlock(DOWN); // 블럭을 한 칸 아래로 이동
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case LEFT: // 화살표 왼쪽 눌렀을 떄
                        gt->MoveBlock(LEFT); // 블럭을 한 칸 왼쪽으로 이동
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case RIGHT: // 화살표 오른쪽 눌렀을 때
                        gt->MoveBlock(RIGHT); // 블럭을 한 칸 오른쪽으로 이동
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    ~GamePlay() { // 게임 종료 이벤트
        delete gt;
    }
};

int main(void) {
    CursorView(false); //콘솔화면 커서 제거
    system("mode con cols=100 lines=40 | title tetris game"); // 콘솔창 크기 및 제목 설정
    //GameTable gt(TABLE_X, TABLE_Y); // 게임판 그리는 객체 생성 -> GamePlay()에서 진행됨
    MainMenu(); // 메인메뉴 그리는 생성자 호출
    GamePlay(); // 게임 플레이
    getchar(); // 이거 없으면 프로그램 바로 종료되어서, 사용자에게 확인할 시간을 주기 위해

    return 0;
}
