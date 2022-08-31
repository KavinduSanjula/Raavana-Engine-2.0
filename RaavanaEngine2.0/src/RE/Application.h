#pragma once

#include "core.h"
#include "Window.h"

#include <string>

class RE_API Application
{

public: 
	Application(const std::string title, uint32_t width, uint32_t height);
	virtual ~Application(){}

	virtual void Run();
	virtual void Loop();

private:
	std::string m_Title;
	uint32_t m_Width, m_Height;

	Window* m_Window;

};

