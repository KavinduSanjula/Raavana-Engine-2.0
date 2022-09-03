#pragma once

Application* OnCreateApplication();

int main() {
	Application* app = OnCreateApplication();
	Application::INSTANCE = app;
	app->Run();
	delete app;
}