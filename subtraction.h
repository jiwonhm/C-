#pragma once
#ifndef SUB
#define SUB

#include <iostream>
#include "display.h"

using namespace std;

namespace cal {
	class subtraction :public display {
	public:
		void showresults(double a, double b);
	};

}
#endif