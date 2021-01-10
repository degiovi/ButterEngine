
workspace "ButterEngine"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory) --
IncludeDir = {}
IncludeDir["GLFW"] = "ButterEngine/thirdparty/GLFW/include"
IncludeDir["Glad"] = "ButterEngine/thirdparty/Glad/include"
IncludeDir["imgui"] = "ButterEngine/thirdparty/imgui"
IncludeDir["glm"] = "ButterEngine/thirdparty/glm"
IncludeDir["stb_image"] = "ButterEngine/thirdparty/stb_image"

group "Dependencies"
	include "ButterEngine/thirdparty/GLFW"
	include "ButterEngine/thirdparty/Glad"
	include "ButterEngine/thirdparty/imgui"

group ""

project "ButterEngine"

	location "ButterEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "btrpch.h"
	pchsource "ButterEngine/src/btrpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/thirdparty/stb_image/**.h",
		"%{prj.name}/thirdparty/stb_image/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/thirdparty/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BTR_PLATFORM_WINDOWS",
			"BTR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BTR_DEBUG"
		runtime "Debug"
		symbols "on"

		
	filter "configurations:Release"
		defines "BTR_RELEASE"
		runtime "Release"
		optimize "on"

		
	filter "configurations:Dist"
		defines "BTR_DIST"
		runtime "Release"
		optimize "on"



project "ButterTextureEditor"

	location "ButterTextureEditor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin/int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ButterEngine/src",
		"ButterEngine/thirdparty/spdlog/include",
		"ButterEngine/thirdparty",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"ButterEngine",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BTR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BTR_DEBUG"
		runtime "Debug"
		symbols "on"

		
	filter "configurations:Release"
		defines "BTR_RELEASE"
		runtime "Release"
		optimize "on"

		
	filter "configurations:Dist"
		defines "BTR_DIST"
		runtime "Release"
		optimize "on"


project "ButterApplication"

	location "ButterApplication"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin/int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ButterEngine/src",
		"ButterEngine/thirdparty/spdlog/include",
		"ButterEngine/thirdparty",
		"%{IncludeDir.glm}"
	}

	links
	{
		"ButterEngine",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"BTR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BTR_DEBUG"
		runtime "Debug"
		symbols "on"

		
	filter "configurations:Release"
		defines "BTR_RELEASE"
		runtime "Release"
		optimize "on"

		
	filter "configurations:Dist"
		defines "BTR_DIST"
		runtime "Release"
		optimize "on"