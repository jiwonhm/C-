#pragma once
#include <iostream>
#ifndef HANDLER
#define HANDLER

namespace cal {
	
	class getInput {
	private:
		double* input;
		char* operations;
		int inputSize;
		int operationSize;

	private:
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
			for (int i; i < operationSize; i++) {
				operations[i] = other.operations[i];
			}
		}

		//coppy assignment



		//Destructor
		~getInput() {
			delete[] operations;
			delete[] input;
		}

	};


}

#endif