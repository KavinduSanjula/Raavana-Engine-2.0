#include <iostream>
#include <SFML/Graphics.hpp>

__declspec(dllexport) void Print(const std::string msg) {
	std::cout << msg << std::endl;
}

__declspec(dllexport) void CreateWindow() {

	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(940, 480), "Raavana Engine 2.0");

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == e.Closed) { window.close(); }
		}

		window.clear(sf::Color(20, 200, 100));
		window.display();
	}

}