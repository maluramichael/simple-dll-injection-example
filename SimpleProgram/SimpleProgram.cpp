#include "pch.h"
#include <iostream>
#include <Windows.h>
int main()
{
	for (int i = 0; i < 20; i++) {
		std::cout << "From simple program " << i << "\n";
		Sleep(1000);
	}
}
