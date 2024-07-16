#pragma once
#include <iostream>
#ifndef DISPLAY
#define DISPLAY
using namespace std;

namespace cal {

	class display {
	public:
		virtual void showresults(double, double)=0;
	};

}

#endif