#pragma once

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>

#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif

using namespace std::literals;

namespace logger = SKSE::log;

namespace util
{
	using SKSE::stl::report_and_fail;

	inline auto MakeHook(REL::ID a_id, std::ptrdiff_t a_offset = 0)
	{
		return REL::Relocation<std::uintptr_t>(a_id, a_offset);
	}

	inline auto MakeHook(REL::Offset a_address, std::ptrdiff_t a_offset = 0)
	{
		return REL::Relocation<std::uintptr_t>(a_address.address() + a_offset);
	}
}

#define MAKE_OFFSET(a_idSE) REL::ID(a_idSE)

#define DLLEXPORT __declspec(dllexport)

#include "Plugin.h"
