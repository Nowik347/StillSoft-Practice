#include "pch.h"
#include "CppUnitTest.h"
#include "../NumberToTextConverter/NumberToTextConverter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestA
{
	TEST_CLASS(UnitTestA)
	{
	public:
		
		bool add_rubles{ false };

		TEST_METHOD(TestMethodA)
		{
			std::string expected{ " ����" };
			char input_numbers[]{ "1" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " ������" };
			char input_numbers[]{ "10" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " ���" };
			char input_numbers[]{ "100" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " ���� ������" };
			char input_numbers[]{ "1 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " ������ �����" };
			char input_numbers[]{ "10 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " ��� �����" };
			char input_numbers[]{ "100 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " ���� �������" };
			char input_numbers[]{ "1 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " ������ ���������" };
			char input_numbers[]{ "10 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " ��� ���������" };
			char input_numbers[]{ "100 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " ��� ����������� ��������� ��� ����������� ����� ��� �����������" };
			char input_numbers[]{ "111 111 111" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(UnitTestB)
	{
	public:

		bool add_rubles{ true };

		TEST_METHOD(TestMethodA)
		{
			std::string expected{ " ���� �����" };
			char input_numbers[]{ "1" };
			
			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " ������ ������" };
			char input_numbers[]{ "10" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " ��� ������" };
			char input_numbers[]{ "100" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " ���� ������ ������" };
			char input_numbers[]{ "1 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " ������ ����� ������" };
			char input_numbers[]{ "10 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " ��� ����� ������" };
			char input_numbers[]{ "100 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " ���� ������� ������" };
			char input_numbers[]{ "1 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " ������ ��������� ������" };
			char input_numbers[]{ "10 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " ��� ��������� ������" };
			char input_numbers[]{ "100 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " ��� ����������� ��������� ��� ����������� ����� ��� ����������� ������" };
			char input_numbers[]{ "111 111 111" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(UnitTestC)
	{
	public:

		bool add_rubles{ false };

		TEST_METHOD(TestMethodA)
		{
			std::string expected{ " ��������� ����������� ���� ��������� ��������� ��������� ��� ������ ��������� ��������� ���" };
			char input_numbers[]{ "485 993 972" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " ������� �������� ����� ��������� ��������� ����������� ����� ����� ��� ��������� ���" };
			char input_numbers[]{ "736 486 193" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " ������� ��������� ��������� ������� ������ ����� �����" };
			char input_numbers[]{ "790 709 006" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " ������ �������� ��� �������� ��������� ���������� ����� ��������� ���������� ����" };
			char input_numbers[]{ "333 917 965" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " ������� ��������� ��������� �������� ��������� ��� ������ ������� ���������� ������" };
			char input_numbers[]{ "590 652 764" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " ��� �������� ����� ��������� ������� ����������� ���� ������ ��������� ��������� ���" };
			char input_numbers[]{ "126 781 492" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " ������� ����� ���� ��������� ������ ���������� ���� ����� �������� �����������" };
			char input_numbers[]{ "745 265 616" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " ������ ����������� ��������� ��� ���������� ����� ������� ����� ���" };
			char input_numbers[]{ "216 160 543" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " ��������� ��������� ������ ��������� ������ ��������� ����� ����� �������� ��������� ���" };
			char input_numbers[]{ "999 376 693" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " ��������� ����� ������ ��������� ������ ��������� ��� ������ �������� ����������" };
			char input_numbers[]{ "948 273 612" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(UnitTestD)
	{
	public:

		bool add_rubles{ true };

		TEST_METHOD(TestMethodA)
		{
			std::string expected{ " ��������� ����������� ���� ��������� ��������� ��������� ��� ������ ��������� ��������� ��� �����" };
			char input_numbers[]{ "485 993 972" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " ������� �������� ����� ��������� ��������� ����������� ����� ����� ��� ��������� ��� �����" };
			char input_numbers[]{ "736 486 193" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " ������� ��������� ��������� ������� ������ ����� ����� ������" };
			char input_numbers[]{ "790 709 006" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " ������ �������� ��� �������� ��������� ���������� ����� ��������� ���������� ���� ������" };
			char input_numbers[]{ "333 917 965" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " ������� ��������� ��������� �������� ��������� ��� ������ ������� ���������� ������ �����" };
			char input_numbers[]{ "590 652 764" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " ��� �������� ����� ��������� ������� ����������� ���� ������ ��������� ��������� ��� �����" };
			char input_numbers[]{ "126 781 492" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " ������� ����� ���� ��������� ������ ���������� ���� ����� �������� ����������� ������" };
			char input_numbers[]{ "745 265 616" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " ������ ����������� ��������� ��� ���������� ����� ������� ����� ��� �����" };
			char input_numbers[]{ "216 160 543" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " ��������� ��������� ������ ��������� ������ ��������� ����� ����� �������� ��������� ��� �����" };
			char input_numbers[]{ "999 376 693" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " ��������� ����� ������ ��������� ������ ��������� ��� ������ �������� ���������� ������" };
			char input_numbers[]{ "948 273 612" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}
	};
}