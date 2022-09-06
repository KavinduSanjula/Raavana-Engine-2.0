#pragma once

//
//						Input class
// 
// This is the main input class for the Raavana Engine 2.0
//


#include "RE/core.h"

#include <tuple>

namespace RE {

	class RE_API Input {

	public:
		static bool IsKeyPressed(KEY key);

		static std::tuple<int, int> GetMousePosition();
		static bool IsMouseButtonPressed(BUTTON button);

	};

}