#pragma once

Application* OnCreateApplication();

int main() {
	Application* app = OnCreateApplication();
	Application::INSTANCE = app;
	app->Start();
	app->Run();
	delete app;
}