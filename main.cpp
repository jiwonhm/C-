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
                    break; // ��ȿ�� �Է��� ������ ���� Ż���Ͽ� ���� ��� ����
                }
                else if (answer == 'n' || answer == 'N') {
                    cout << "\n";
                    cout << "Thank you" << endl;
                    return 0; // ���α׷� ����
                }
                else {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            }

		} while (answer == 'y' || answer == 'Y');

		return 0;
	}
