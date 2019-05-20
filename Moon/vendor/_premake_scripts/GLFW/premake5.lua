project "GLFW"
  kind "StaticLib"
  language "C"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  filedir = "../../GLFW/"

  files
  {
    filedir .. "include/GLFW/glfw3.h",
    filedir .. "include/GLFW/glfw3native.h",
    filedir .. "src/context.c",
    filedir .. "src/init.c",
    filedir .. "src/input.c",
    filedir .. "src/monitor.c",
    filedir .. "src/vulkan.c",
    filedir .. "src/window.c"
    }
    
  filter "system:windows"
    systemversion "latest"
    staticruntime "On"

    files
    {
      filedir .. "src/win32_init.c",
      filedir .. "src/win32_joystick.c",
      filedir .. "src/win32_monitor.c",
      filedir .. "src/win32_time.c",
      filedir .. "src/win32_thread.c",
      filedir .. "src/win32_window.c",
      filedir .. "src/wgl_context.c",
      filedir .. "src/egl_context.c",
      filedir .. "src/osmesa_context.c"
    }

    defines 
    { 
      "_GLFW_WIN32",
      "_CRT_SECURE_NO_WARNINGS"
    }
    filter { "system:windows", "configurations:Release" }
      buildoptions "/MT"
