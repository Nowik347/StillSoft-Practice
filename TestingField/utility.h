#ifndef MY_UTILITY
#define MY_UTILITY

const char* g_dictionary[3][2][3][10]                                // �������� ���������� �������
{                                                                    // ������ ������� g_dictionary[���� ��������][���� ������][������][�����]
    {                                                                                                                                       // [���� ��������] - ������������
        {                                                                                                                                   // � �������� ��� ������ ����������
            { "", " ����", " ���", " ���", " ������", " ����", " �����", " ����", " ������", " ������" },
            { "", " ������", " ��������", " ��������", " �����", " ���������", " ����������", " ���������", " �����������", " ���������" }, // [���� ������] - ��������� ���������
            { "", " ���", " ������", " ������", " ���������", " �������", " ��������", " �������", " ���������", " ���������" }             // ����� �������� � ���������� ���������
        },
        {                                                                                                                                   // [������][�����] - ������������ ���
            { "", " ����", " ���", " ���", " ������", " ����", " �����", " ����", " ������", " ������" },                                   // ���������������� ������� � ��������� �������
            { "", " ������", " ��������", " ��������", " �����", " ���������", " ����������", " ���������", " �����������", " ���������" },
            { "", " ���", " ������", " ������", " ���������", " �������", " ��������", " �������", " ���������", " ���������" }
        }
    },
    {
        {
            { " ������", " �����������", " ����������", " ����������", " ������������", " ����������", " �����������", " ����������", " ������������", " ������������"},
            { "", "", "", "", "", "", "", "", "", "" },
            { "", " ���", " ������", " ������", " ���������", " �������", " ��������", " �������", " ���������", " ���������" },
        },
        {
            { " ������", " �����������", " ����������", " ����������", " ������������", " ����������", " �����������", " ����������", " ������������", " ������������"},
            { "", "", "", "", "", "", "", "", "", "" },
            { "", " ���", " ������", " ������", " ���������", " �������", " ��������", " �������", " ���������", " ���������" },
        }
    },
    {
        {
            {" ������", " �����", " �����", " �����", " �����", " ������", " ������", " ������", " ������", " ������"},
            {" �����", " ������", " ������", " ������", " ������", " �����", " �����", " �����", " �����", " �����"},
            {" ���������", " �������", " ��������", " ��������", " ��������", " ���������", " ���������", " ���������", " ���������", " ���������"}
        },
        {
            {" ������", " �����", " �����", " �����", " �����", " ������", " ������", " ������", " ������", " ������"},
            {" �����", " �����", " �����", " �����", " �����", " �����", " �����", " �����", " �����", " �����"},
            {" ���������", " ���������", " ���������", " ���������", " ���������", " ���������", " ���������", " ���������", " ���������", " ���������"}
        }
    }
};

//_______________________________________________________________________________________________________________________________________________________________________
void reverseArray(int* array, int length)                                       // ������� ��������������� �������
{
    for (int i{ 0 }, j{ length - 1 }; i < j; i++, j--)
        std::swap(array[i], array[j]);
}
//_______________________________________________________________________________________________________________________________________________________________________
int* convertCharArrToIntArr(char input[], int& length)                          // ����������� ������� �������� � ��������� �� ������������� ������
{
    bool exit{ false };
    length = 0;

    while (!exit)                                                               // ��������� �� ������� ������ �����
    {
        switch (isdigit(input[length]))
        {
        case 0:
            if (input[length] == '\0')
            {
                exit = true;
                break;
            }
            else
            {
                std::cout << "����������� ����.";
                return NULL;
            }
        default:
            length++;
            break;
        }
    }

    int* result_array{ new int[length] };                                       // ������� ���������

    for (int i{ 0 }; i <= length; i++)                                          // �������� ������
        result_array[i] = input[i] - '0';

    return result_array;                                                        // ���������� ���������
}

#endif