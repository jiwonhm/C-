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
		double result = numbers[0]; //√ ±‚»≠

		for (int i = 0; i < opSize; i++) {
			result = applyOperation(result, numbers[i + 1], op[i]);
		}

		return result;
	}
}

