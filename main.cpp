#include <iostream>
#include "display.h"
#include "operations.h"



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
				addition add1;
				add1.add(number, number2);
				break;
			}
			case '-': {
				subtraction sub1;
				sub1.sub(number, number2);
				break;
			}

			case '*': {
				multiplication multi1;
				multi1.multi(number, number2);
				break;
			}

			case '/': {
				division div1;
				div1.div(number, number2);
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
