#pragma once
#include <iostream>
#ifndef OPERATION
#define OPERATION

namespace cal {
	class addition {
	public:
		double add(double a, double b);
	};

	class subtraction {
	public:
		double sub(double a, double b);
	};

	class multiplication {
	public:
		double multi(double a, double b);
	};

	class division {
	public:
		double div(double a, double b);
	};

}

#endif