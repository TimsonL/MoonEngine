workspace "MoonEngine"
  architecture "x64"
  
  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Moon"
  location "Moon"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "pch.h"
  pchsource "Moon/src/pch.cpp"

  files
  {
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/src",
    "%{prj.name}/vendor/spdlog/include"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "MOON_PLATFORM_WIN",
      "MOON_BUILD_DLL",
      "_WINDLL"
    }

    postbuildcommands
    {
      ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

   filter "configurations:Debug"
    defines "MOON_DEBUG"
    symbols "On"

   filter "configurations:Release"
    defines "MOON_RELEASE"
    optimize "On"

   filter "configurations:Dist"
    defines "MOON_DIST"
    optimize "On"
  
project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"

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
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "MOON_PLATFORM_WIN"
    }

  filter "configurations:Debug"
  defines "MOON_DEBUG"
  symbols "On"

  filter "configurations:Release"
  defines "MOON_RELEASE"
  optimize "On"

  filter "configurations:Dist"
  defines "MOON_DIST"
  optimize "On"
