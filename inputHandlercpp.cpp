#include <iostream>
#include "inputHandler.h"

using namespace std;

namespace cal {
	void getInput::userinput() {
		double num;
		char op = ' ';
		
		cout << "input the expression (end with '='): ";
		
		while (op != '=') {
			cin >> num;

			//alert when user inputs wrong things
			if (cin.fail()) {
				cin.clear(); // Clear the stream state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ingnore the invlid input
				continue; // Skip to the next iteration of the loop
			}
			


			double* newInput = new double[inputSize + 1];

			for (int i = 0; i < inputSize; i++) {
				newInput[i] = input[i];
			}
		
			newInput[inputSize] = num;

			delete[] input; 
			input = newInput; //input �����Ϳ� ���� �Ҵ�� �迭�� �ּ� �Ҵ�
			inputSize++;

			cin >> op;
			if (op == '=') { //'='�� �� ����
				break;
			}
			
			// Skip to the next iteration of the loop
			if (op != '+' && op != '-' && op != '*' && op != '/') {
				cout<< "Invalid operator. Please enter a valid operator: ";
				continue; 
			}



			char* newOperation = new char[operationSize + 1];
			for (int i = 0; i < operationSize; i++) {
				newOperation[i] = operations[i];
			}
			
			newOperation[operationSize] = op;

			delete[] operations;
			operations = newOperation;
			operationSize++;
		}

	}

	
	double* getInput::getInputs() const { //input�迭�� ������ ��ȯ
		return input;
	}

	char* getInput::getOperations() const {
		return operations; //������ �迭 ��ȯ
	}

	int getInput::getInputSize() const { //�Էµ� ������ ���� ��ȯ
		return inputSize;
	}

	int getInput::getOperationSize() const {
		return operationSize; //�Էµ� ������ ���� ��ȯ
	}



}


