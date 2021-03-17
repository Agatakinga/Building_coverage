#include "Test.h"
#include <vector>
#include "BuildingCoverage.h"

bool TestSingleElement()
{
	std::vector<int> H = { 5 };
	int expected_result = 5;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestOneMaxValueInMiddle()
{
	std::vector<int> H = { 2, 3, 1, 5, 3, 4, 3 };
	int expected_result = 9 + 20;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestOneMaxValueAtBegin()
{
	std::vector<int> H = { 5, 4, 2 };
	int expected_result = 12;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestOneMaxValueAtEnd()
{
	std::vector<int> H = { 2, 4, 5 };
	int expected_result = 12;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesInMiddle()
{
	std::vector<int> H = { 2, 3, 5, 2, 5, 4 };
	int expected_result = 6 + 20;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesAtBegin()
{
	std::vector<int> H = { 5, 2, 5, 3, 3 };
	int expected_result = 15 + 6;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}

bool TestMoreMaxValuesAtEnd()
{
	std::vector<int> H = { 3, 3, 5, 2, 5 };
	int expected_result = 15 + 6;
	int result = solution(H);

	return (expected_result == result) ? true : false;
}
