#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public RE::Application {
public:
	Sandbox()
		:Application("Sandbox", 1280, 720)
	{

	}

	void Start() override {
		std::string name = "Sanju";
		RE_LOG_ERROR("Name = %s", name.c_str());
		

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