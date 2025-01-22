workspace "Hazel"
	architecture "x86_64"

	configurations { "Debug", "Release", "Dist" }
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


	project "Hazel"
		location "Hazel"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "hzpch.h"
		pchsource "Hazel/src/hzpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs {
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
		}

		filter "system:windows"
			cppdialect "C++20"
			staticruntime "On"
			systemversion "latest"
			
			defines
			{
				"HZ_PLATFORM_WINDOWS",
				"HZ_BUILD_DLL"
			}
			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"

		filter "configurations:Release"
		defines "HZ_RELEASE"
			optimize "On"

		filter "configurations:Dist"
		defines "HZ_DIST"
			optimize "On"

		filter { "system:windows", "configurations:Release"}
			buildoptions { "/utf-8"}  -- Agrega estas l�neas para habilitar UTF-8
		filter { "system:windows", "configurations:Debug"}
			buildoptions { "/utf-8"}  -- Agrega estas l�neas para habilitar UTF-8

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

		includedirs {
			"Hazel/vendor/spdlog/include",
			"Hazel/src"
		}

		links {
			"Hazel"
		}

		filter "system:windows"
			cppdialect "C++20"
			staticruntime "On"
			systemversion "10.0"

			defines
			{
				"HZ_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "HZ_DEBUG"
			symbols "On"
		filter "configurations:Release"
		defines "HZ_RELEASE"
			optimize "On"
		filter "configurations:Dist"
		defines "HZ_DIST"
			optimize "On"
		
		filter { "system:windows", "configurations:Release"}
			buildoptions { "/utf-8"}  -- Agrega estas l�neas para habilitar UTF-8
		filter { "system:windows", "configurations:Debug"}
			buildoptions { "/utf-8"}  -- Agrega estas l�neas para habilitar UTF-8
