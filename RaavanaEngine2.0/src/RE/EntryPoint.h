#pragma once

Application* OnCreateApplication();

int main() {
	Application* app = OnCreateApplication();
	app->Run();
	delete app;
}