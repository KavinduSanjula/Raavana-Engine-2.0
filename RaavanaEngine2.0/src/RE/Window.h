#pragma once

#include "core.h"
#include <string>

class RE_API Window {

public:
	virtual ~Window() {}
	virtual void Update() = 0;

public:
	static Window* Create(const std::string title, uint32_t width, uint32_t height);
};