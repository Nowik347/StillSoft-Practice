#include "pch.h"
#include "CppUnitTest.h"
#include "../Prototype_4/Prototype_4.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestA
{
	TEST_CLASS(UnitTestA)
	{
	public:
		
		std::string answers[2][10]
		{
			{" один", " дес€ть", " сто", " одна тыс€ча", " дес€ть тыс€ч", " сто тыс€ч", " один миллион", " дес€ть миллионов", " сто миллионов",
			" сто одиннадцать миллионов сто одиннадцать тыс€ч сто одиннадцать"},

			{" четыреста восемьдес€т п€ть миллионов дев€тьсот дев€носто три тыс€чи дев€тьсот семьдес€т два", " семьсот тридцать шесть миллионов четыреста восемьдес€т шесть тыс€ч сто дев€носто три",
			 " семьсот дев€носто миллионов семьсот дев€ть тыс€ч шесть", " триста тридцать три миллиона дев€тьсот семнадцать тыс€ч дев€тьсот шестьдес€т п€ть",
			 " п€тьсот дев€носто миллионов шестьсот п€тьдес€т две тыс€чи семьсот шестьдес€т четыре", " сто двадцать шесть миллионов семьсот восемьдес€т одна тыс€ча четыреста дев€носто два",
			 " семьсот сорок п€ть миллионов двести шестьдес€т п€ть тыс€ч шестьсот шестнадцать", " двести шестнадцать миллионов сто шестьдес€т тыс€ч п€тьсот сорок три",
			 " дев€тьсот дев€носто дев€ть миллионов триста семьдес€т шесть тыс€ч шестьсот дев€носто три", " дев€тьсот сорок восемь миллионов двести семьдес€т три тыс€чи шестьсот двенадцать"}
		};

		int inputs[2][10]
		{
			{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 111111111},
			{485993972, 736486193, 790709006, 333917965, 590652764, 126781492, 745265616, 216160543, 999376693, 948273612}
		};

		TEST_METHOD(TestMethodA)
		{
			std::string expected{}, result{};
			int count{ 0 }, final_count{ 20 }, module_count{ 0 };

			for (short i{ 0 }; i < 2; i++)
			{
				module_count = 0;

				for (short j{ 0 }; j < 10; j++)
				{
					expected = answers[i][j];

					std::vector<int> input_numbers = convertIntToVector(inputs[i][j]);

					numConverter converter{ input_numbers };

					result = converter.convertNum();

					if (result == expected)
					{
						count++;
						module_count++;

						Logger::WriteMessage(" Test complete ");
					}
					else
					{
						Logger::WriteMessage(" Test failed ");
					}
				}

				if (module_count == 10)
				{
					Logger::WriteMessage(" Module operational \n");
				}
				else
				{
					Logger::WriteMessage(" Module failed \n");
				}
			}

			// Test
			Assert::AreEqual(final_count, count);
		}
	};
}