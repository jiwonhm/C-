#pragma once
#ifndef ADD
#define ADD


#include <iostream>
#include "display.h"

namespace cal {

	class addition : public display {
	public:
		void showresults(double a, double b);
	};

}

#endif