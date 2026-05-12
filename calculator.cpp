#include <iostream>

class Calculator
{
private :
	
	double num1,result, num2 = 1.0;
	char operation;
	int userChoice;
	
	double plus()
	{
		return num1 + num2;
	}

	double minus()
	{
		return num1 - num2;
	}

	double multiply()
	{
		return num1 * num2;
	}
	
	double divide()
	{
		return num1 / num2;
	}
	
	void checker(double num2,char operation)
	{
		if (operation == '/' && num2 == 0)
		{
			std::cout << "Error: Division by zero is not allowed." << std::endl;
			exit(1);
		}
	}

	void calculate()
	{
		std::cout << "---CALCULATOR---" << std::endl;
		std::cout << "Enter first number you want to work with: " << std::endl;
		std::cin >> num1;
		std::cout << "Enter second number you want to work with: " << std::endl;
		std::cin >> num2;
		std::cout << "Enter the operation you want to perform (+, -, *, /): " << std::endl;
		std::cin >> operation;
		checker(num2, operation);
		if (operation == '+')
		{
			result = plus();
		}
		else if (operation == '-')
		{
			result = minus();
		}
		else if (operation == '*')
		{
			result = multiply();
		}
		else if (operation == '/')
		{
			result = divide();
		}
		else
		{
			std::cout << "Error: Invalid operation." << std::endl;
			exit(1);
		}
	}

	void display()
	{
		std::cout << "Result: " << result << std::endl;
	}

	void clear()
	{
		num1 = 0.0;
		num2 = 0.0;
		result = 0.0;
		operation = ' ';
	}

	void choice()
	{
		std::cout << "Do you want to perform another calculation? (1 for Yes, 0 for No): " << std::endl;
		std::cin >> userChoice;
		if (userChoice == 1)
		{
			clear();
			run();
		}
		else if (userChoice == 0)
		{
			std::cout << "Thank you for using the calculator. Goodbye!" << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "Error: Invalid choice." << std::endl;
			exit(1);
		}
	}

public:

	void run()
	{
		calculate();
		display();
		choice();
	}

};

int main()
{
	Calculator calc;
	calc.run();
	return 0;
}