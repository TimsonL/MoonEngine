workspace "MoonEngine"
  architecture "x64"
  
  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Moon/vendor/_premake_scripts/GLFW"

IncludeDir = {}
IncludeDir["GLFW"] = "Moon/vendor/GLFW/include"

project "Moon"
  location "Moon"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "on"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "pch.h"
  pchsource "Moon/src/pch.cpp"

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  defines
  {
    "_CRT_SECURE_NO_WARNINGS"
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include",
    "%{IncludeDir.GLFW}"
  }

  links
  {
    "GLFW",
    "opengl32.lib"
  }

  filter "system:windows"
    systemversion "latest"

    defines
    {
      "MOON_PLATFORM_WIN"
    }

  filter "configurations:Debug"
  defines "MOON_DEBUG"
  symbols "on"

  filter "configurations:Release"
  defines "MOON_RELEASE"
  optimize "on"

  filter "configurations:Dist"
  defines "MOON_DIST"
  optimize "on"
  
project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++17"
  staticruntime "on"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs 
  {
    "Moon/vendor/spdlog/include",
    "Moon/src"
  }

  links
  {
    "Moon"
  }

  filter "system:windows"
    systemversion "latest"

    defines
    {
      "MOON_PLATFORM_WIN"
    }

  filter "configurations:Debug"
    defines "MOON_DEBUG"
    symbols "on"

  filter "configurations:Release"
    defines "MOON_RELEASE"
    optimize "on"

  filter "configurations:Dist"
    defines "MOON_DIST"
    optimize "on"
