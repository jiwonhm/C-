#include <iostream>
#include "display.h"


using namespace std;
using namespace cal;

	int main() {
		double number, number2;
		char op, answer;

		do {//1. 여러개 연산 
			//2. *,/ 먼저 계산 가능하게
			cout << "Enter first number, operator(+,-,*,/) and second number: ";
			cin >> number >> op >> number2;

		
			switch (op) {
			case '+': {
				addition add;
				add.showresults(number, number2);
				break;
			}
			case '-': {
				subtraction sub;
				sub.showresults(number, number2);
				break;
			}

			case '*': {
				multiplication mul;
				mul.showresults(number, number2);
				break;
			}

			case '/': {
				division div;
				div.showresults(number, number2);
				break;
			}

			default:
				cout << "Enter the correct operator (+,-,/,*)";
				break;
			}

			cout << "Do you want to perform another calculation? (y/n): ";
			cin >> answer;
			cout << '\n';
		
		} while (answer=='y'||answer=='Y');
		return 0;

	}
