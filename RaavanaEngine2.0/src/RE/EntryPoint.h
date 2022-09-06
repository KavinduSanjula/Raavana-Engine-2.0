#pragma once

//
//								Main entry point for the Raavana Engine 
// 
// This will include in client application and automaticaly creates the entry point. The OnCreateApplication() function
// should be created in client code. OnCreateApplication() function returns a pointer of Application instance.
// 
//

RE::Application* OnCreateApplication();	 // need to be implement in client app

int main() {
	RE::Application* app = OnCreateApplication();
	RE::Application::INSTANCE = app;
	app->Start();
	app->Run();
	delete app;
}