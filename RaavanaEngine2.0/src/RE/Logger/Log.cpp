#include "Log.h"

namespace RE {

	Log* Log::INSTANCE = nullptr;


	void Log::Info(const std::string msg) {
		std::cout << "\x1B[44m[RE]\033[0m(\x1B[32mERROR\033[0m) - " << msg << std::endl;
	}

	void Log::Warn(const std::string msg) {
		std::cout << "\x1B[44m[RE]\033[0m(\x1B[33mERROR\033[0m) - " << msg << std::endl;
	}

	void Log::Error(const std::string msg) {
		std::cout << "\x1B[44m[RE]\033[0m(\x1B[31mERROR\033[0m) - " << msg << std::endl;
	}

}