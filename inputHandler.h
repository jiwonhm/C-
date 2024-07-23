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

		void userinput();


	};


}

#endif