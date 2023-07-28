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
			std::string expected{ " один" };
			char input_numbers[]{ "1" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " десять" };
			char input_numbers[]{ "10" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " сто" };
			char input_numbers[]{ "100" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " одна тысяча" };
			char input_numbers[]{ "1 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " десять тысяч" };
			char input_numbers[]{ "10 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " сто тысяч" };
			char input_numbers[]{ "100 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " один миллион" };
			char input_numbers[]{ "1 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " десять миллионов" };
			char input_numbers[]{ "10 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " сто миллионов" };
			char input_numbers[]{ "100 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " сто одиннадцать миллионов сто одиннадцать тысяч сто одиннадцать" };
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
			std::string expected{ " один рубль" };
			char input_numbers[]{ "1" };
			
			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " десять рублей" };
			char input_numbers[]{ "10" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " сто рублей" };
			char input_numbers[]{ "100" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " одна тысяча рублей" };
			char input_numbers[]{ "1 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " десять тысяч рублей" };
			char input_numbers[]{ "10 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " сто тысяч рублей" };
			char input_numbers[]{ "100 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " один миллион рублей" };
			char input_numbers[]{ "1 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " десять миллионов рублей" };
			char input_numbers[]{ "10 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " сто миллионов рублей" };
			char input_numbers[]{ "100 000 000" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " сто одиннадцать миллионов сто одиннадцать тысяч сто одиннадцать рублей" };
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
			std::string expected{ " четыреста восемьдесят пять миллионов девятьсот девяносто три тысячи девятьсот семьдесят два" };
			char input_numbers[]{ "485 993 972" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " семьсот тридцать шесть миллионов четыреста восемьдесят шесть тысяч сто девяносто три" };
			char input_numbers[]{ "736 486 193" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " семьсот девяносто миллионов семьсот девять тысяч шесть" };
			char input_numbers[]{ "790 709 006" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " триста тридцать три миллиона девятьсот семнадцать тысяч девятьсот шестьдесят пять" };
			char input_numbers[]{ "333 917 965" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " пятьсот девяносто миллионов шестьсот пятьдесят две тысячи семьсот шестьдесят четыре" };
			char input_numbers[]{ "590 652 764" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " сто двадцать шесть миллионов семьсот восемьдесят одна тысяча четыреста девяносто два" };
			char input_numbers[]{ "126 781 492" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " семьсот сорок пять миллионов двести шестьдесят пять тысяч шестьсот шестнадцать" };
			char input_numbers[]{ "745 265 616" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " двести шестнадцать миллионов сто шестьдесят тысяч пятьсот сорок три" };
			char input_numbers[]{ "216 160 543" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " девятьсот девяносто девять миллионов триста семьдесят шесть тысяч шестьсот девяносто три" };
			char input_numbers[]{ "999 376 693" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " девятьсот сорок восемь миллионов двести семьдесят три тысячи шестьсот двенадцать" };
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
			std::string expected{ " четыреста восемьдесят пять миллионов девятьсот девяносто три тысячи девятьсот семьдесят два рубля" };
			char input_numbers[]{ "485 993 972" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodB)
		{
			std::string expected{ " семьсот тридцать шесть миллионов четыреста восемьдесят шесть тысяч сто девяносто три рубля" };
			char input_numbers[]{ "736 486 193" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodC)
		{
			std::string expected{ " семьсот девяносто миллионов семьсот девять тысяч шесть рублей" };
			char input_numbers[]{ "790 709 006" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodD)
		{
			std::string expected{ " триста тридцать три миллиона девятьсот семнадцать тысяч девятьсот шестьдесят пять рублей" };
			char input_numbers[]{ "333 917 965" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodE)
		{
			std::string expected{ " пятьсот девяносто миллионов шестьсот пятьдесят две тысячи семьсот шестьдесят четыре рубля" };
			char input_numbers[]{ "590 652 764" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodF)
		{
			std::string expected{ " сто двадцать шесть миллионов семьсот восемьдесят одна тысяча четыреста девяносто два рубля" };
			char input_numbers[]{ "126 781 492" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodG)
		{
			std::string expected{ " семьсот сорок пять миллионов двести шестьдесят пять тысяч шестьсот шестнадцать рублей" };
			char input_numbers[]{ "745 265 616" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodH)
		{
			std::string expected{ " двести шестнадцать миллионов сто шестьдесят тысяч пятьсот сорок три рубля" };
			char input_numbers[]{ "216 160 543" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodI)
		{
			std::string expected{ " девятьсот девяносто девять миллионов триста семьдесят шесть тысяч шестьсот девяносто три рубля" };
			char input_numbers[]{ "999 376 693" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMethodJ)
		{
			std::string expected{ " девятьсот сорок восемь миллионов двести семьдесят три тысячи шестьсот двенадцать рублей" };
			char input_numbers[]{ "948 273 612" };

			// Call main() in your test
			std::string result = numToTextConvert(input_numbers, add_rubles);

			// Test
			Assert::AreEqual(expected, result);
		}
	};
}