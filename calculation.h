#pragma once
#include <iostream>
#include "operations.h"
#ifndef CAL
#define CAL

namespace cal {

	class calculation{
	private:
		double applyOperation(double a, double b, char op);
		addition addOp;
		subtraction subOp;
		multiplication mulOp;
		division divOp;

	public:
		double evaluate(const double* numbers, const char* op, int numSize, int opSize); //숫자, 오퍼레이션 시작 주소, 
	};

}

#endif