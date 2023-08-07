//#include <iostream>
//
//const int g_input_length{ 10 };
//
//void reverseArray(int *array, int length)
//{
//    for (int i{ 0 }, j{ length - 1 }; i < j; i++, j--)
//    {
//        std::swap(array[i], array[j]);
//    }
//}
//
//int* convertCharArrToIntArr(char input[], int& length)
//{
//    bool exit{ false };
//    length = 0;
//
//    while (!exit)
//    {
//        switch (isdigit(input[length]))
//        {
//        case 0:
//            if (input[length] == '\0')
//            {
//                exit = true;
//                break;
//            }
//            else
//            {
//                std::cout << "Некоректный ввод.";
//                exit = true;
//                break;
//            }
//        default:
//            length++;
//            break;
//        }
//    }
//
//    int* result_array{ new int[length] };
//
//    for (int i{ 0 }; i <= length; i++)
//    {
//        switch (isdigit(input[i]))
//        {
//        case 0:
//            break;
//        default:
//            result_array[i] = input[i] - '0';
//            break;
//        }
//    }
//
//    return result_array;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Rus");
//
//    char starting_input[g_input_length];
//
//    std::cin.getline(starting_input, g_input_length);
//
//    int length{ 0 }, *input_numbers{ convertCharArrToIntArr(starting_input, length) };
//
//    reverseArray(input_numbers, length);
//
//    for (int i{ 0 }; i < length; i++)
//    {
//        std::cout << input_numbers[i] << ' ';
//    }
//}