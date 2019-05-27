project "imgui"
    kind "StaticLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    imguifiledir = "../../imgui"

    files
    {
        imguifiledir .. "imconfig.h",
        imguifiledir .. "imgui.h",
        imguifiledir .. "imgui.cpp",
        imguifiledir .. "imgui_draw.cpp",
        imguifiledir .. "imgui_internal.h",
        imguifiledir .. "imgui_widgets.cpp",
        imguifiledir .. "imstb_rectpack.h",
        imguifiledir .. "imstb_textedit.h",
        imguifiledir .. "imstb_truetype.h",
        imguifiledir .. "imgui_demo.cpp"
    }
    
    filter "system:windows"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "On"
        
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"
