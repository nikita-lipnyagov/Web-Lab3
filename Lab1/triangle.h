#pragma once
#ifndef methods
#define methods

struct Triangle
{
	int base_length;
	int side_lenght;
public:
	Triangle(int base, int side) {
		base_length = base;
		side_lenght = side;
	}
	Triangle() {}
	void change_size(int percentages);

	double calculate_median(bool is_it_base);

	double calculate_perimeter();
	
	double calculate_area();
	
	double calculate_angles(bool is_it_base_angles);
};
#endif