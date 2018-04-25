#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <cmath> 
#include "triangle.h"

using namespace std;

void Triangle::change_size(int percentages)
{
	base_length += base_length * percentages / 100;
	side_lenght += side_lenght * percentages / 100;
}

double Triangle::calculate_median(bool is_it_base)
{
	int a = side_lenght;
	int b = base_length;
	if (is_it_base)
	{
		return 0.5 * sqrt(4 * a * a - b * b);
	}
	else
		return 0.5 * sqrt(2 * b * b + a * a);
}

double Triangle::calculate_perimeter()
{
	return 2 * side_lenght + base_length;
}

double Triangle::calculate_area()
{
	int a = side_lenght;
	int b = base_length;
	return 0.5 * (b * sqrt(a * a - 0.25 * b * b));
}

double Triangle::calculate_angles(bool is_it_base_angles)
{
	int a = side_lenght;
	int b = base_length;
	double base_angles = acos(b / (2 * a)) * 180 / 3.14;

	if (is_it_base_angles)
	{
		return base_angles;
	}
	else
		return 180 - base_angles;
}