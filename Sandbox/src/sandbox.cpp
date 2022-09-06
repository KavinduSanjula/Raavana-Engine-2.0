#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:
	Sandbox()
		:Application("Sandbox", 1280, 720)
	{

	}

	void Start() override {
		RE_LOG_INFO("Hello logger");
		RE_LOG_WARN("Hello logger");
		RE_LOG_ERROR("Hello logger");
		

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