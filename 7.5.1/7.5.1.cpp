#include <iostream>

int calculate(int num1, int num2, char action)
{
	switch (action)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		if (num2 != 0)
		{
			return num1 / num2;
		}
		else
		{
			std::cout << "Invalid input!\n";
			return 0;
		}
	case '%':
		if (num2 != 0)
		{
			return num1 % num2;
		}
		else
		{
			std::cout << "Invalid input!\n";
			return 0;
		}
	default:
		std::cout << "Invalid input!\n";
		return 0;
	}
}

int main()
{
	int num1, num2, result;
	char action;

	std::cout << "Enter the first integer: "; std::cin >> num1;

	std::cout << "Enter the second integer: "; std::cin >> num2;

	std::cout << "Choose an action (+, -, *, /, or %): "; std::cin >> action;

	std::cout << num1 << ' ' << action << ' ' << num2 << " = " << calculate(num1, num2, action);
}