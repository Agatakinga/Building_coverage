#include "BuildingCoverage.h"
#include <algorithm>

int solution(std::vector<int> &H)
{
	int maximum_value = *std::max_element(H.begin(), H.end());
	const int maximum_coverage = maximum_value * H.size();

	int minimum_coverage = maximum_coverage;

	int maximum_value_left = 0, maximum_value_right = 0;

	for (unsigned int i = 0; i < H.size(); i++) //od lewej do prawej
	{
		if (H[i] == maximum_value)
			break;

		maximum_value_left = std::max(maximum_value_left, H[i]); //4

		int new_minimum_coverage = maximum_coverage - ((i + 1) * maximum_value - (i + 1) * maximum_value_left);
		minimum_coverage = std::min(minimum_coverage, new_minimum_coverage);
	}

	for (int i = (H.size() - 1); i >= 0; i--) //od prawej do lewej
	{
		if (H[i] == maximum_value)
			break;

		maximum_value_right = std::max(maximum_value_right, H[i]);

		int new_minimum_coverage = maximum_coverage - ((H.size() - i) * maximum_value - (H.size() - i) * maximum_value_right);
		minimum_coverage = std::min(minimum_coverage, new_minimum_coverage);
	}

	return minimum_coverage;
}

/*
int solution(std::vector<int> &buildings)
{
	int total_width = buildings.size();
	int total_maximum_height = *std::max_element(buildings.begin(), buildings.end());

	int one_banner_surface = total_width * total_maximum_height;

	int minimum_surface = one_banner_surface;

	for (std::vector<int>::iterator i1 = buildings.begin() + 1; i1 != buildings.end(); i1++) // begin + 1 (szerokosc to minum 1)
	{
		int point_of_division_index = std::distance(buildings.begin(), i1);

		int height_of_the_first_banner = *std::max_element(buildings.begin(), buildings.begin() + point_of_division_index);

		int surface_of_the_first_banner = height_of_the_first_banner * point_of_division_index;

		int height_of_the_second_banner = 0;

		if (height_of_the_first_banner == total_maximum_height)
			height_of_the_second_banner = *std::max_element(buildings.begin() + point_of_division_index, buildings.end());
		else
			height_of_the_second_banner = total_maximum_height;

		int surface_of_the_second_banner = height_of_the_second_banner * (total_width - point_of_division_index);

		int surface_of_two_banners = surface_of_the_first_banner + surface_of_the_second_banner;

		if (minimum_surface > surface_of_two_banners)
			minimum_surface = surface_of_two_banners;
	}

	return minimum_surface;
}
*/
