#include <iostream>
#include "calculation.h"

using namespace std;

namespace cal {

	double calculation::applyOperation(double a, double b, char op) {
		switch (op) {
		case '+': {
			return addOp.add(a, b);
		}
		case '-': {
			return subOp.sub(a, b);
		}
		case '*': {
			return mulOp.multi(a, b);
		}
		case '/': {
			return divOp.div(a, b);
		}
		default: {
			return 0;
		}

		}
	}

	double calculation::evaluate(const double* numbers, const char* op, int numSize, int opSize) {
	
	
			//[ * and / ]are must be calculated at first
			double* intermediateNumbers = new double[numSize];
			char* intermediateOps = new char[opSize];
			int intermediateNumSize = 0;
			int intermediateOpSize = 0;

			intermediateNumbers[intermediateNumSize++] = numbers[0];


			for (int i = 0; i < opSize; i++) {
				if (op[i] == '*' || op[i] == '/') {
					double result = applyOperation(intermediateNumbers[intermediateNumSize - 1], numbers[i + 1], op[i]);
					intermediateNumbers[intermediateNumSize - 1] = result;
				}
				else {
					intermediateOps[intermediateOpSize++] = op[i];
					intermediateNumbers[intermediateNumSize++] = numbers[i + 1];
				}
			}

			// 2. µ¡¼À°ú »¬¼ÀÀ» Ã³¸®
			double result = intermediateNumbers[0];
			for (int i = 0; i < intermediateOpSize; i++) {
				result = applyOperation(result, intermediateNumbers[i + 1], intermediateOps[i]);
			}

			delete[] intermediateNumbers;
			delete[] intermediateOps;

			return result;
	}
}

