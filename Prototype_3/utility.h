#ifndef MY_UTILITY
#define MY_UTILITY

//_______________________________________________________________________________________________________________________________________________________________________
std::string reference[5][10]                                         // ���������� �������
{                                                                    // �������� �������
    { "", " ���", " ������", " ������", " ���������", " �������", " ��������", " �������", " ���������", " ���������" },
    { "", " ����", " ���", " ���", " ������", " ����", " �����", " ����", " ������", " ������" },
    { "", " ������", " ��������", " ��������", " �����", " ���������", " ����������", " ���������", " �����������", " ���������" },
    { " ������", " �����������", " ����������", " ����������", " ������������", " ����������", " �����������", " ����������", " ������������", " ������������" },
    { "", " ����", " ���", " ���", " ������", " ����", " �����", " ����", " ������", " ������" }
}, util[2][10]                                                       // ��������������� �������
{
    {" �����", " ������", " ������", " ������", " ������", " �����", " �����", " �����", " �����", " �����"},
    {" ���������", " �������", " ��������", " ��������", " ��������", " ���������", " ���������", " ���������", " ���������", " ���������"}
};
//_______________________________________________________________________________________________________________________________________________________________________
class numConverter                                                        // ����� �����������
{
private:

    short pointer{ 0 }, curr_class{ 0 }, class_sum{ 0 };                  // ��������
    std::string numbers[3][10];                                           // ������� �����
    std::string class_names[10];                                          // ������� �������� �������
    std::stack<int> input_nums{};                                         // ���� �����

    void loadTeens()                                                      // ������� ����������� ����� �� 10 �� 19
    {
        std::copy(reference[3], reference[3] + 10, numbers[2]);                 // �������� ������

        std::fill_n(class_names, 10, util[curr_class / 2][0]);

        pointer++;
        input_nums.pop();                                                       // ���������� �������
    }

    void loadTens()                                                       // ������� ����������� ����� �� 10 �� 90    
    {
        std::copy(reference[2], reference[2] + 10, numbers[2]);                 // �������� ������

        checkClass();
    }

    void clearClass()
    {
        std::fill_n(class_names, 10, "");
    }

    void loadClass(int needed_class)
    {
        std::copy(util[needed_class], util[needed_class] + 10, class_names);
        
        if(!needed_class)
            std::copy(reference[4], reference[4] + 10, numbers[2]);
    }

    void checkClass()
    {
        if (curr_class == 0)
            clearClass();
        else
            loadClass(curr_class / 2);
    }

    std::string getClass()                                             // ������� ������ ������������ ������
    {
        return pointer == 2 ? class_names[input_nums.top()] : "";               // ���������� ������������ ������
    }

    std::string getNumStr()
    {
        return numbers[pointer][input_nums.top()];
    }

    void exceptionsCheck()
    {
        if (pointer == 1)                                                       // ��������� �������
        {
            input_nums.top() == 1 ? loadTeens() : loadTens();
        }
        else
        {
            curr_class = input_nums.size() / 3;
            checkClass();
        }
    }

    void shiftPointer()                                                   // ������� ���������� ��������
    {
        input_nums.pop();                                                       // ������� � ���������� �����

        pointer == input_nums.size() % 3;                                 // ����� ��������

        if (!input_nums.empty())
        {
            pointer == 2 ? class_sum = 0 : class_sum += input_nums.top();           // �� ������ ������ �������
            exceptionsCheck();
        }
    }

public:

    numConverter(std::stack<int>& input)                                  // �����������
    {
        input_nums = input;                                                     // �������� ����

        for (short i{ 0 }; i < 3; i++)                                          // ��������� ������� � ������� �����
            std::copy(reference[i], reference[i] + 10, numbers[i]);

        if (input_nums.size() % 3 != 0)                                         // ������� ��������� ������
            input_nums.size() % 3 == 1 ? pointer = 2 : pointer = 1;

        curr_class = input_nums.size() / 3;
        exceptionsCheck();
    }

    std::string outputString()                                            // ������� ������ ������ �������� �����
    {
        std::string result{ getNumStr() + getClass() };

        shiftPointer();

        return result;
    }

    bool finished()
    {
        return false;
    }
};
//_______________________________________________________________________________________________________________________________________________________________________
std::stack<int> convertIntToStack(int input)
{
    assert(input > 0);

    std::stack<int> temp;

    while (input > 0)
    {
        temp.push(input % 10);
        input /= 10;
    }

    return temp;
}
#endif