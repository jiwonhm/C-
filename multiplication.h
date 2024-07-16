#pragma once
#ifndef MUL
#define MUL
#include <iostream>
#include "display.h"

using namespace std;

namespace cal {
	class multiplication : public display {
	public:
		void showresults(double a, double b) override;
	};

}
#endif