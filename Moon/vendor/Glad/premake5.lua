project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    Gladfiledir = "../../Glad/"

    files
    {
        Gladfiledir .. "include/glad/glad.h",
        Gladfiledir .. "include/KHR/khrplatform.h",
        Gladfiledir .. "src/glad.c"
    }

    includedirs
    {
        Gladfiledir .. "include"
    }
    
    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
