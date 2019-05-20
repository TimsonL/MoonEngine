#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace moon {

  class MOON_API Log
  {
  public:
    static void Init();
    static void Shutdown();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };

}

// Core logger macros
#define MOON_CORE_TRACE(...) moon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MOON_CORE_INFO(...)  moon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MOON_CORE_WARN(...)  moon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MOON_CORE_ERROR(...) moon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MOON_CORE_FATAL(...) moon::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logger macros
#define MOON_TRACE(...)      moon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MOON_INFO(...)       moon::Log::GetClientLogger()->info(__VA_ARGS__)
#define MOON_WARN(...)       moon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MOON_ERROR(...)      moon::Log::GetClientLogger()->error(__VA_ARGS__)
#define MOON_FATAL(...)      moon::Log::GetClientLogger()->critical(__VA_ARGS__)
