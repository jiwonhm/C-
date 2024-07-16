#pragma once
#include <iostream>
#include "addition.h"


namespace cal {

	
		void addition::showresults(double a, double b){
			double result = a + b;
			cout << "the result is " <<result <<"\n";
		}

}
