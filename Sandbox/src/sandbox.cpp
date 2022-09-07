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
		RE::Shape* shape = RE::Rect::Create(20,20, 50,50);
		shape->Draw();
		delete shape;
	}


};

RE::Application* OnCreateApplication() {
	return new Sandbox();
}