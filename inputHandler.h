#pragma once
#include <iostream>
#include <cstring>
#ifndef HANDLER
#define HANDLER

namespace cal {
	
	class getInput {
	private:
		double* input;
		char* operations;
		int inputSize;
		int operationSize;

	public:
		getInput():input(nullptr), operations(nullptr),inputSize(0),operationSize(0){}
		
		//rule of three
		//copy constructor
		getInput(const getInput& other) {
			inputSize = other.inputSize;
			operationSize = other.operationSize;
			
			input = new double[inputSize];
			for (int i = 0; i < inputSize; i++) {
				input[i] = other.input[i];
			}

			operations = new char[operationSize];
			for (int i=0; i < operationSize; i++) {
				operations[i] = other.operations[i];
			}
		}

		//coppy assignment
		getInput& operator=(const getInput& other) {
			if (this != &other) {
				delete[] input;
				delete[] operations;

				inputSize = other.inputSize;
				operationSize = other.operationSize;

			
				input = new double[other.inputSize];
				for (int i = 0; i < inputSize; i++) {
					input[i] = other.input[i];
				}

				operations = new char[other.operationSize + 1];
				strcpy(operations, other.operations);

			}
			return *this;
		}


		//Destructor
		~getInput() {
			delete[] operations;
			delete[] input;
		}

		void userinput(); //숫자 연산자 반복해서 입력받고 = 받으면 입력 중지하는 역할
		double* getInputs() const;//input배열의 포인터 반환
		
		
		char* getOperations() const; //연산자 배열 반환
		
		
		int getInputSize() const; //입력된 숫자의 개수 반환
			

		int getOperationSize() const; //입력된 연산자 개수 반환
		
	};


}

#endif