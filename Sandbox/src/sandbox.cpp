#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public Application {
public:
	Sandbox()
		:Application("Sandbox", 1280, 720)
	{

	}

	void Start() override {
		std::cout << "Starting Application" << std::endl;
	}

	void Loop() override {
		//auto [x, y] = Input::GetMousePosition();
		//std::cout << x << ", " << y << std::endl;
		if (Input::IsMouseButtonPressed(RE_BUTTON::Left)) {
			std::cout << "clicked" << std::endl;
		}
	}


};

Application* OnCreateApplication() {
	return new Sandbox();
}