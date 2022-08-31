#include <string>

__declspec(dllimport) void Print(const std::string msg);

int main() {

	Print("Hello World");

}