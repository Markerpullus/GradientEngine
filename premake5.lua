workspace "Gradient"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SPDLOG"] = "Gradient/vendor/spdlog/include"
IncludeDir["GLFW"] = "Gradient/vendor/glfw/include"
IncludeDir["GLAD"] = "Gradient/vendor/glad/include"
IncludeDir["BOOST"] = "Gradient/vendor/boost"
IncludeDir["GLM"] = "Gradient/vendor/glm"

include "Gradient/vendor/glfw"
include "Gradient/vendor/glad"

project "Gradient"
	location "Gradient"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

		"%{prj.name}/vendor/boost/**.hpp",
		"%{prj.name}/vendor/glm/**.hpp",
		"%{prj.name}/vendor/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.SPDLOG}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.BOOST}",
		"%{IncludeDir.GLM}"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"GD_PLATFORM_WINDOWS",
			"GD_BUILD_DLL"
		}

		links
		{
			"GLFW",
			"Glad",
			"opengl32.lib"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GD_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "GD_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"

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
		"Gradient/src",
		"%{IncludeDir.SPDLOG}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.BOOST}",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Gradient"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"GD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GD_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "GD_DIST"
		optimize "On"