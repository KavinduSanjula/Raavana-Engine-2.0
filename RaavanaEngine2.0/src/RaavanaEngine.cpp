#include <iostream>

__declspec(dllexport) void Print(const std::string msg) {
	std::cout << msg << std::endl;
}