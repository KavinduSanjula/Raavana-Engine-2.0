#pragma once

#include "RE/core.h"

#include <iostream>
#include <string>

namespace RE {

	class RE_API Log {

	public:

		void Info(const std::string msg);
		void Warn(const std::string msg);
		void Error(const std::string msg);

		static Log* INSTANCE;

	};

}

#ifdef RE_DEBUG

#define RE_LOG_INFO(msg)	RE::Log::INSTANCE->Info(msg)
#define RE_LOG_WARN(msg)	RE::Log::INSTANCE->Warn(msg)
#define RE_LOG_ERROR(msg)	RE::Log::INSTANCE->Error(msg)

#else

#define RE_LOG_INFO(msg)	// RE::Log::INSTANCE->Info(msg)
#define RE_LOG_WARN(msg)	// RE::Log::INSTANCE->Warn(msg)
#define RE_LOG_ERROR(msg)	// RE::Log::INSTANCE->Error(msg)

#endif