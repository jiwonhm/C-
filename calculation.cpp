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
			double* intermediateNumbers = new double[numSize]; //중간 계산 결과 저장
			char* intermediateOps = new char[opSize]; //나중에 처리할 연산자 저장
			int intermediateNumSize = 0; //배열에 저장된 숫자의 갯수
			int intermediateOpSize = 0; //

			intermediateNumbers[intermediateNumSize++] = numbers[0];


			for (int i = 0; i < opSize; i++) {
				if (op[i] == '*' || op[i] == '/') {
					double result = applyOperation(intermediateNumbers[intermediateNumSize - 1], numbers[i + 1], op[i]); //현재까지 계산된 가장 최근의 숫자, 현재 연산자 다음에 위치한 숫자, 연산자 
					intermediateNumbers[intermediateNumSize - 1] = result;
				}
				else {
					intermediateOps[intermediateOpSize++] = op[i]; //+,- 인덱스 저장
					intermediateNumbers[intermediateNumSize++] = numbers[i + 1];
				}
			}

			// 2. 덧셈과 뺄셈을 처리
			double result = intermediateNumbers[0];
			for (int i = 0; i < intermediateOpSize; i++) {
				result = applyOperation(result, intermediateNumbers[i + 1], intermediateOps[i]);
			}

			delete[] intermediateNumbers;
			delete[] intermediateOps;

			return result;
	}
}

