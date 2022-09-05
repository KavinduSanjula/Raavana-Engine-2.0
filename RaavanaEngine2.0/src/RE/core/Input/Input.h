#pragma once

//
//						Input class
// 
// This is the main input class for the Raavana Engine 2.0
//


#include "RE/core.h"

#include <tuple>

class RE_API Input {

public:
	static bool IsKeyPressed(RE_KEY key);

	static std::tuple<int, int> GetMousePosition();
	static bool IsMouseButtonPressed(RE_BUTTON button);

};