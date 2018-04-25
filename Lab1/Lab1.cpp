#include "stdafx.h"
#include <windows.h>
#include "triangle.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{


	//Пример url 

	cout << "Content-Type: text/html\n\n";
	cout << "<HTML><HEAD><TITLE>Lab3</TITLE></HEAD>\n";
	cout << "<body link='#FF9900' vlink='#FF9900' alink='#FF9900'>\n";
	cout << "<meta http-equiv='content-type' content='text/html; charset=windows-1251'>\n";
	cout << "<p style='line-height:100%; margin-left:10%;' align='center'><span style='font-size:14pt;'>Cgi-скрипт на С++.</span></p>\n";

	char comment[256];
	Triangle triangle;

	int number_of_chars = GetEnvironmentVariable(L"QUERY_STRING", (LPWSTR)comment, 256);
	
	vector<string> commands;  
	string buffer = "";
	for (int i = 0; i < 256; i++) {
		if (comment[i] != ',') { 
			buffer += comment[i];
		}
		else {
			commands.push_back(buffer);
			buffer = "";
		}
	}

	triangle.base_length = atoi(commands[0].c_str());
	triangle.side_lenght = atoi(commands[0].c_str());

	cout << "<p> Характеристики: </p>";
	cout << "<p>Median " << triangle.calculate_median(true) << "</p>";
	cout << "<p>Perimeter: " << triangle.calculate_perimeter() << "</p>";
	cout << "<p>Area: " << triangle.calculate_area() << "</p>";
	cout << "<p>Base angle: " << triangle.calculate_angles(true) << "</p>";
	cout << "<p>Side angle: " << triangle.calculate_angles(false) << "</p>";
	triangle.change_size(100);
	cout <<"<p>base: " << triangle.base_length <<"  side: " << triangle.side_lenght << "</p>";

    return 0;
}

