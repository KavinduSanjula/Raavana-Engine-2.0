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
		//std::cout << "Loop runnig..." << std::endl;
	}


	void OnKeyPressed(KeyPressed* e) const override{
		if (e->GetKey() == RE_Key::A) {
			std::cout << "A key pressed" << std::endl;
		}
	}

	void OnMouseButtonPressed(MouseButtonPressed* e) const override {

		auto [x, y] = e->GetMousePosition();
		std::cout << "(" << e->GetButton() << " - " << x << ", " << y << ")" << std::endl;

	}

	void OnMouseMoved(MouseMoved* e) const override {
		auto [x, y] = e->GetMousePosition();
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

};

Application* OnCreateApplication() {
	return new Sandbox();
}