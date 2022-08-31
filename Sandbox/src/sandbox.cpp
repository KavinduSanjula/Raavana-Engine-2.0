#include <RaavanaEngine.h>
#include <iostream>

class Sandbox : public Application {
public:
	Sandbox()
		:Application("Sandbox", 1280, 720)
	{

	}

	void Loop() override {
		std::cout << "Loop runnig..." << std::endl;
	}
};

Application* OnCreateApplication() {
	return new Sandbox();
}