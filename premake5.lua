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
IncludeDir["ENTT"] = "Gradient/vendor/entt/src"
IncludeDir["GLM"] = "Gradient/vendor/glm"
IncludeDir["STB"] = "Gradient/vendor/stb"
IncludeDir["TOL"] = "Gradient/vendor/tinyobjloader"

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
		"%{prj.name}/src/**",

		"%{prj.name}/vendor/boost/**.hpp",
		"%{prj.name}/vendor/entt/src/**.hpp",
		"%{prj.name}/vendor/glm/**.hpp",
		"%{prj.name}/vendor/glm/**.inl",
		"%{prj.name}/vendor/stb/**",
		"%{prj.name}/vendor/tinyobjloader/**"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.SPDLOG}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.BOOST}",
		"%{IncludeDir.ENTT}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.STB}",
		"%{IncludeDir.TOL}"
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
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestGame")
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

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/MDd"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MD"

project "TestGame"
	location "TestGame"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**"
	}

	includedirs
	{
		"Gradient/src",
		"%{IncludeDir.SPDLOG}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.BOOST}",
		"%{IncludeDir.ENTT}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.STB}",
		"%{IncludeDir.TOL}"
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