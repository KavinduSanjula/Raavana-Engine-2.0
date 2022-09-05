#pragma once

//
//								Main entry point for the Raavana Engine 
// 
// This will include in client application and automaticaly creates the entry point. The OnCreateApplication() function
// should be created in client code. OnCreateApplication() function returns a pointer of Application instance.
// 
//

Application* OnCreateApplication();	 // need to be implement in client app

int main() {
	Application* app = OnCreateApplication();
	Application::INSTANCE = app;
	app->Start();
	app->Run();
	delete app;
}