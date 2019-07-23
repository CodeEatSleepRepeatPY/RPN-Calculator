#include <iostream>
#include <string>
#include <typeinfo>
#include <stack>
#include <Windows.h>

int main(){
	SetConsoleTitleA("RPN Calculator Made By - -");

	std::stack<double> stack;

	double lastPopped = NULL;

	double num1 = NULL;

	double num2 = NULL;
	
	char op = NULL;
	
	int counter = 0;

	while (true) {

		if (!num1 && counter == 0) {
			std::cout << "Number: ";
			std::cin >> num1;
			counter++;
		}
		if (!num2 && counter == 1) {
			std::cout << "Number: ";
			std::cin >> num2;
			counter++;
		}
		if (!op && counter == 2) {
			std::cout << "Operator: ";
			std::cin >> op;
			counter++;
		}
		if (counter == 3) {

			switch (op) {
			case '*':
				stack.push(num1 * num2);
				std::cout << "Calculated answer: " << num1 * num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				counter++;
				break;

			case '/':
				stack.push(num1 / num2);
				std::cout << "Calculated answer: " << num1 / num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				counter++;
				break;

			case '+':
				stack.push(num1 + num2);
				std::cout << "Calculated answer: " << num1 + num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				counter++;
				break;

			case '-':
				stack.push(num1 - num2);
				std::cout << "Calculated answer: " << num1 - num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				counter++;
				break;
			}
		}

		if (counter == 4) {

			std::cout << "Number: ";
			std::cin >> num2;
			std::cout << "Operator: ";
			std::cin >> op;
		
			switch (op) {
			case '*':
				stack.push(lastPopped * num2);
				std::cout << "Calculated answer: " << lastPopped * num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				break;

			case '/':
				stack.push(lastPopped / num2);
				std::cout << "Calculated answer: " << lastPopped / num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				break;

			case '+':
				stack.push(lastPopped + num2);
				std::cout << "Calculated answer: " << lastPopped + num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				break;

			case '-':
				stack.push(lastPopped - num2);
				std::cout << "Calculated answer: " << lastPopped - num2 << std::endl;
				lastPopped = stack.top();
				stack.pop();
				break;
			}
		}
		
	}

	system("PAUSE");
	return 0;

}
