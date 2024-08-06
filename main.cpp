#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "inputHandler.h"
#include "operations.h"
#include "calculation.h"



using namespace std;
using namespace cal;

	int main() {
		char answer;
		do {
			getInput inputHandler;
			inputHandler.userinput();

			calculation calc;
			double result = calc.evaluate(inputHandler.getInputs(), inputHandler.getOperations(), inputHandler.getInputSize(), inputHandler.getOperationSize());

			cout << "The result is: " << result << "\n" << endl;


            while (true) {
                cout << "Do you want to another calculation? (y/n): ";
                cin >> answer;

                if (answer == 'y' || answer == 'Y') {
                    break; // 유효한 입력을 받으면 루프 탈출하여 다음 계산 수행
                }
                else if (answer == 'n' || answer == 'N') {
                    cout << "\n";
                    cout << "Thank you" << endl;
                    return 0; // 프로그램 종료
                }
                else {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            }

		} while (answer == 'y' || answer == 'Y');

		return 0;
	}
