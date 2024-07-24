#include <iostream>
#include "inputHandler.h"

using namespace std;

namespace cal {
	void getInput::userinput() {
		double num;
		char op;
		
		cout << "input the expression (end with '='): ";
		
		while (op != '=') {
			cin >> num;
			double* newInput = new double[inputSize + 1];

			for (int i = 0; i < inputSize; i++) {
				newInput[i] = input[i];
			}
		
			newInput[inputSize] = num;

			delete[] input; 
			input = newInput; //input 포인터에 새로 할당된 배열의 주소 할당
			inputSize++;

			cin >> op;
			if (op == '"') { //'='일 때 종료
				break;
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

	
	double* getInput::getInputs() const { //input배열의 포인터 반환
		return input;
	}

	char* getInput::getOperations() const {
		return operations; //연산자 배열 반환
	}

	int getInput::getInputSize() const { //입력된 숫자의 개수 반환
		return inputSize;
	}

	int getInput::getOperationSize() const {
		return operationSize; //입력된 연산자 개수 반환
	}



}


