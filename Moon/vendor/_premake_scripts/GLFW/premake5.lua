project "GLFW"
  kind "StaticLib"
  language "C"
  
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  GLFWfiledir = "../../GLFW/"

  files
  {
    GLFWfiledir .. "include/GLFW/glfw3.h",
    GLFWfiledir .. "include/GLFW/glfw3native.h",
    GLFWfiledir .. "src/context.c",
    GLFWfiledir .. "src/init.c",
    GLFWfiledir .. "src/input.c",
    GLFWfiledir .. "src/monitor.c",
    GLFWfiledir .. "src/vulkan.c",
    GLFWfiledir .. "src/window.c"
    }
    
  filter "system:windows"
    systemversion "latest"
    staticruntime "On"

    files
    {
      GLFWfiledir .. "src/win32_init.c",
      GLFWfiledir .. "src/win32_joystick.c",
      GLFWfiledir .. "src/win32_monitor.c",
      GLFWfiledir .. "src/win32_time.c",
      GLFWfiledir .. "src/win32_thread.c",
      GLFWfiledir .. "src/win32_window.c",
      GLFWfiledir .. "src/wgl_context.c",
      GLFWfiledir .. "src/egl_context.c",
      GLFWfiledir .. "src/osmesa_context.c"
    }

    defines 
    { 
      "_GLFW_WIN32",
      "_CRT_SECURE_NO_WARNINGS"
    }
    filter { "system:windows", "configurations:Release" }
      buildoptions "/MT"
