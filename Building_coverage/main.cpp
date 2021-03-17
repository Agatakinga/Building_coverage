/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
#include "Test.h"
#include "BuildingCoverage.h"

std::mt19937& rng()
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937 g(seed);
	return g;
}

int random(int min, int max)
{
	std::uniform_real_distribution <double> d(min, max);
	return d(rng());
}

int main()
{   
	std::cout << "Test Single Element: " << (TestSingleElement() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test One Max Value In Middle: " << (TestOneMaxValueInMiddle() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test One Max Value At Begin: " << (TestOneMaxValueAtBegin() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test One Max Value At End: " << (TestOneMaxValueAtEnd() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test More Max Values In Middle: " << (TestMoreMaxValuesInMiddle() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test More Max Values At Begin: " << (TestMoreMaxValuesAtBegin() ? "Pass" : "Fail") << std::endl;
	std::cout << "Test More Max Values At End: " << (TestMoreMaxValuesAtEnd() ? "Pass" : "Fail") << std::endl;

	std::cout << "\nPerformance: " << std::endl;

	std::vector<int> B = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

	for (auto building_height : B)
	{
		std::vector<int> H{};
		int number_of_buildings = building_height;

		for (int i = 0; i < number_of_buildings; i++)
			H.push_back(random(1, 10000));

		auto start = std::chrono::high_resolution_clock::now();
		solution(H);
		auto finish = std::chrono::high_resolution_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
		//std::cout << std::fixed << std::setprecision(9) << std::left;
		std::cout << "Test time of execution for: " << number_of_buildings << " elements: " << std::chrono::nanoseconds(finish-start).count() / 1000 << " [us]" << std::endl;
	}
}

