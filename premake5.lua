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
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hmpch.h"
	pchsource "HazmatEngine/src/hmpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS",
			"HM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	staticruntime "off"

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
		"HazmatEngine/vendor/spdlog/include",
		"HazmatEngine/src"
	}

	links
	{
		"HazmatEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HM_DIST"
		runtime "Release"
		optimize "On"