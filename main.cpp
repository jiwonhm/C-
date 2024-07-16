#include <iostream>
#include "display.h"
#include "addition.h"
#include "subtraction.h"
#include "division.h"
#include "multiplication.h"

using namespace std;
using namespace cal;

	int main() {
		double number, number2;
		char op;

		while (true) {

			cout << "Enter first number: ";
			cin >> number;

			cout << "Enter an operator(+,-,*,/): ";
			cin >> op;

			cout << "Enter second number: ";
			cin >> number2;

			switch (op) {
			case '+': {
				addition add;
				add.showresults(number, number2);
				cout << "\n";
				break;
			}
			case '-': {
				subtraction sub;
				sub.showresults(number, number2);
				cout << "\n";
				break;
			}

			case '*': {
				multiplication mul;
				mul.showresults(number, number2);
				cout << "\n";
				break;
			}

			case '/': {
				division div;
				div.showresults(number, number2);
				cout << "\n";
				break;
			}

			default:
				cout << "Enter the correct operator (+,-,/,*)";
				cout << "\n";
				break;
			}
		}
		return 0;

	}
