#pragma once
#ifndef DIV
#define DIV
#include <iostream>
#include "display.h"

using namespace std;
namespace cal {

	class division : public display {
	public:
		void showresults(double a, double b);
	};
}

#endif