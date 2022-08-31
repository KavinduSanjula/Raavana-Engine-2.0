#include <string>

__declspec(dllimport) void Print(const std::string msg);
__declspec(dllimport) void CreateWindow();

int main() {

	Print("Hello World");
	CreateWindow();

}