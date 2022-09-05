#pragma once

//
//						Window Class
// This is the main window class for the Raavana Engine 2.0
//

#include "core.h"
#include <string>

class RE_API Window {

public:
	virtual ~Window() {}
	virtual void Update() = 0; // Updates the window in every frame
	virtual void* GetNativeWindow() const = 0; // method to get native window instance as void*

public:
	static Window* Create(const std::string title, uint32_t width, uint32_t height); // this method used for create window class independently from SFML
};