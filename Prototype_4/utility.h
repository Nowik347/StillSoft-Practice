#ifndef MY_UTILITY
#define MY_UTILITY

std::string reference[5][10]                                         // √лобальные словари
{                                                                    // ќсновной словарь
    { "", " сто", " двести", " триста", " четыреста", " п€тьсот", " шестьсот", " семьсот", " восемьсот", " дев€тьсот" },
    { "", " один", " два", " три", " четыре", " п€ть", " шесть", " семь", " восемь", " дев€ть" },
    { "", " дес€ть", " двадцать", " тридцать", " сорок", " п€тьдес€т", " шестьдес€т", " семьдес€т", " восемьдес€т", " дев€носто" }, 
    { " дес€ть", " одиннадцать", " двенадцать", " тринадцать", " четырнадцать", " п€тнадцать", " шестнадцать", " семнадцать", " восемнадцать", " дев€тнадцать" },
    { "", " одна", " две", " три", " четыре", " п€ть", " шесть", " семь", " восемь", " дев€ть" }
}, util[2][10]                                                       // ¬спомогательный словарь
{
    {" тыс€ч", " тыс€ча", " тыс€чи", " тыс€чи", " тыс€чи", " тыс€ч", " тыс€ч", " тыс€ч", " тыс€ч", " тыс€ч"},
    {" миллионов", " миллион", " миллиона", " миллиона", " миллиона", " миллионов", " миллионов", " миллионов", " миллионов", " миллионов"}
};
//_______________________________________________________________________________________________________________________________________________________________________
class numConverter
{
private:
    std::string result_string;                                 // —трока вывода
    std::string numbers[3][10], class_names[10];               // —ловарь текущего разр€да

    std::vector<int> input_nums{};

    short rank_sum{ 0 };

    void loadTeens()
    {
        std::copy(reference[3], reference[3] + 10, numbers[1]);
        std::fill_n(numbers[2], 10, "");

        loadClassEx();
    }

    void loadTens()
    {
        std::copy(reference[1], reference[1] + 10, numbers[1]);
        std::copy(reference[2], reference[2] + 10, numbers[2]);

        loadClass();
    }

    void loadClass()
    {
        if (rank_sum == 0 || input_nums.size() <= 3)
        {
            std::fill_n(class_names, 10, "");
        }
        else if (input_nums.size() <= 6)
        {
            std::copy(util[0], util[0] + 10, class_names);
            std::copy(reference[4], reference[4] + 10, numbers[1]);
        }
        else
        {
            std::copy(util[1], util[1] + 10, class_names);
        }
    }

    void loadClassEx()
    {
        if (rank_sum == 0 || input_nums.size() <= 3)
        {
            std::fill_n(class_names, 10, "");
        }
        else if (input_nums.size() <= 6)
        {
            std::fill_n(class_names, 10, util[0][0]);
        }
        else
        {
            std::fill_n(class_names, 10, util[1][0]);
        }
    }

public:

    numConverter(std::vector<int> input)
    {
        for (short i{ 0 }; i < 3; i++)
            std::copy(reference[i], reference[i] + 10, numbers[i]);

        input_nums = input;

        rank_sum += input_nums[0];

        loadClass();
    }

    std::string convertNum()
    {
        while (!input_nums.empty())
        {
            rank_sum += input_nums[0];

            if (input_nums.size() % 3 == 2)
                input_nums[0] == 1 ? loadTeens() : loadTens();

            result_string += numbers[input_nums.size() % 3][input_nums[0]];

            if (input_nums.size() % 3 == 1)
            {
                rank_sum = 0;
                result_string += class_names[input_nums[0]];
            }

            input_nums.erase(input_nums.begin());
        }

        return result_string;
    }
};
//_______________________________________________________________________________________________________________________________________________________________________
std::vector<int> convertIntToVector(int input)
{
    assert(input > 0);

    std::vector<int> temp;

    while (input > 0)
    {
        temp.insert(temp.begin(), input % 10);
        input /= 10;
    }

    return temp;
}
#endif