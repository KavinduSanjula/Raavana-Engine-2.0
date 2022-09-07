#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:
	Sandbox()
		:Application("Sandbox", 1280, 720)
	{
		RE_LOG_INFO("Sandbox created!");
	}

	void Start() override {
		RE_LOG_INFO("Starting Raavana Engine 2.0");
	}

	void Loop() override {
		if (RE::Input::IsKeyPressed(RE::KEY::Enter)) {
			std::cout << "Enter Pressed" << std::endl;
		}
	}


};

RE::Application* OnCreateApplication() {
	return new Sandbox();
}