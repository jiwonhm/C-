#pragma once
#include <iostream>
#include "display.h"
#ifndef CAL
#define CAL

namespace cal {

	class calculation: public display {
	public:
		void showresults();
	};

}

#endif