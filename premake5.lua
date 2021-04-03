workspace "HazmatEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "HazmatEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "HazmatEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "HazmatEngine/vendor/imgui"

include "HazmatEngine/vendor/GLFW"
include "HazmatEngine/vendor/Glad"
include "HazmatEngine/vendor/imgui"

project "HazmatEngine"
	location "HazmatEngine"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hmpch.h"
	pchsource "HazmatEngine/src/hmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.ini"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
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
		"HazmatEngine/vendor/spdlog/include",
		"HazmatEngine/src",
        "HazmatEngine/vendor",
        "%{IncludeDir.glm}"
	}

	links
	{
		"HazmatEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "on"