// ConsoleApCal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include"stdafx.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <Windows.h>

class PaliCal
{
public:
	PaliCal();
	~PaliCal();

private:

};

void TimeWaste(int n)
{
	double value = 0.0;
	double sigma = 1.23333333;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			value += (double)(i + j) / sigma;
			char strDes[1000];
			char * strSrc = "This is test for waste time,,,,,,,,,,,,,,,,,,,,,,,,,,,";
			strcpy_s(strDes, strSrc);
		}
		Sleep(1);
	}
}

PaliCal::PaliCal()
{
	int ans = 0;
	for (int i = 9999; i > 0; i--) {
		for (int j = 9999; j >= 0; j--) {
			int num = i * 999 + j; //output all numbers between 0to999*999
			std::stringstream stream;
			stream << num;
			std::string digits = stream.str();
			int numlength = digits.length();

			bool p = true;
			for (int it = 0; it < numlength / 2 + 1; it++) {
				if (digits[it] != digits[numlength - 1 - it]) {
					p = false;
					break;
				}
			}
			if (p) ans = std::fmaxl(ans, num);
		}
	}
	std::cout << "Largest palindromic number: " << ans << std::endl;
}

PaliCal::~PaliCal()
{
}

int main()
{
	std::vector<std::thread> threads;
	for (size_t i = 0; i < 2; i++)
	{
		threads.push_back(std::thread([]() {
			std::cout << "Cur id" << std::this_thread::get_id() << std::endl;
			PaliCal pali;
		}));
	}
	for (auto && thread : threads)
	{
		thread.join();
	}
	return 0;
}
