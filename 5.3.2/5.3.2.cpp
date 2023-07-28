#include <iostream>

bool isEven(int input)
{
	if (input % 2 == 0)
		return true;
	else
		return false;
}

int main()
{
    int input;

    std::cout << "Enter an integer: ";
    std::cin >> input;

	switch (isEven(input))
	{
	case true:
		std::cout << input << " is even";
		break;
	case false:
		std::cout << input << " is odd";
		break;
	default:
		break;
	}
}