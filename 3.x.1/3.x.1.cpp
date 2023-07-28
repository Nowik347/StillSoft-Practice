#include <iostream>

int readNumber()
{
	int num;

	std::cout << "Please enter a number: ";
	std::cin >> num;

	return num;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x;
}

int main()
{
	int x{};
	x = readNumber() + readNumber();
	writeAnswer(x);

	return 0;
}