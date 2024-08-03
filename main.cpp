#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "inputHandler.h"
#include "operations.h"
#include "calculation.h"



using namespace std;
using namespace cal;

	int main() {
	
		getInput inputHandler;
		inputHandler.userinput();

		calculation calc;
		double result = calc.evaluate(inputHandler.getInputs(), inputHandler.getOperations(), inputHandler.getInputSize(), inputHandler.getOperationSize());

		cout << "The result is: " << result << endl;

		return 0;
	}
