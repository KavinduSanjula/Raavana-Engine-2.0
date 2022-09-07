#pragma once

#include "RE/core.h"

#include <iostream>
#include <string>

namespace RE {

	class RE_API Log {

	public:

		static Log* INSTANCE;

		template<typename... Args>
		void Info(Args... args) {
			printf("\x1B[44m[RE-LOG]\033[0m (\x1B[32minfo\033[0m) | ");
			Print(std::forward<Args>(args)...);
			printf("\n");
		}

		template<typename... Args>
		void Warn(Args... args) {
			printf("\x1B[44m[RE]\033[0m (\x1B[33mwarn\033[0m) | ");
			Print(std::forward<Args>(args)...);
			printf("\n");
		}

		template<typename... Args>
		void Error(Args... args) {
			printf("\x1B[44m[RE]\033[0m (\x1B[31merror\033[0m) | ");
			Print(std::forward<Args>(args)...);
			printf("\n");
		}
	private:
		template<typename... Args>
		void Print(Args... args) {
			printf(std::forward<Args>(args)...);
		}

	};

}

#ifdef RE_DEBUG

#define RE_LOG_INFO(...)	RE::Log::INSTANCE->Info(__VA_ARGS__)
#define RE_LOG_WARN(...)	RE::Log::INSTANCE->Warn(__VA_ARGS__)
#define RE_LOG_ERROR(...)	RE::Log::INSTANCE->Error(__VA_ARGS__)

#else

#define RE_LOG_INFO(msg)	// RE::Log::INSTANCE->Info(__VA_ARGS__)
#define RE_LOG_WARN(msg)	// RE::Log::INSTANCE->Warn(__VA_ARGS__)
#define RE_LOG_ERROR(msg)	// RE::Log::INSTANCE->Error(__VA_ARGS__)

#endif