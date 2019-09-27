-- Cortablo-Engine --
-- Copyright (c) 2019 Cortablo. All rights reserved. --

workspace "Cortablo-Engine"
	architecture "x86" -- Available: x86, x64, ARM --
	
	configurations
	{
		"Debug",
		"Release",
	}

	flags
	{
		"MultiProcessorCompile"
	}

	project "Cortablo-Engine"
		location "%{prj.name}"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		targetdir "bin/%{prj.name}-%{cfg.architecture}-%{cfg.buildcfg}"
		objdir "bin-int/%{prj.name}-%{cfg.architecture}-%{cfg.buildcfg}"
	
		IncludeDirs = {}
		IncludeDirs["SDL2"] = "%{prj.name}/vendor/SDL2/include"
		IncludeDirs["GLEW"] = "%{prj.name}/vendor/GLEW/include"
		IncludeDirs["glm"] = "%{prj.name}/vendor/glm/include"
		IncludeDirs["FreeType2"] = "%{prj.name}/vendor/FreeType2/include"
		IncludeDirs["jsoncpp"] = "%{prj.name}/vendor/jsoncpp/include"
		IncludeDirs["lua"] = "%{prj.name}/vendor/lua/include"
		IncludeDirs["stb_image"] = "%{prj.name}/vendor/stb_image/include"
		
		LibDirs = {}
		LibDirs["SDL2"] = "%{prj.name}/vendor/SDL2/lib/%{cfg.architecture}"
		LibDirs["GLEW"] = "%{prj.name}/vendor/GLEW/lib/Release/Win32"
		LibDirs["FreeType2"] = "%{prj.name}/vendor/FreeType2/lib/%{cfg.architecture}/%{cfg.buildcfg}"
		LibDirs["jsoncpp"] = "%{prj.name}/vendor/jsoncpp/lib/%{cfg.architecture}/%{cfg.buildcfg}"
		LibDirs["lua"] = "%{prj.name}/vendor/lua/lib/%{cfg.architecture}"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		
		defines
		{
			"GLEW_STATIC"
		}
		
		includedirs
		{
			"%{IncludeDirs.SDL2}",
			"%{IncludeDirs.GLEW}",
			"%{IncludeDirs.glm}",
			"%{IncludeDirs.FreeType2}",
			"%{IncludeDirs.jsoncpp}",
			"%{IncludeDirs.lua}",
			"%{IncludeDirs.stb_image}"
		}

		libdirs
		{
			"%{LibDirs.SDL2}",
			"%{LibDirs.GLEW}",
			"%{LibDirs.FreeType2}",
			"%{LibDirs.jsoncpp}",
			"%{LibDirs.lua}",
		}
		
		links
		{
			"SDL2.lib",
			"SDL2main.lib",
			"SDL2_mixer.lib",
			"freetype.lib",
			"opengl32.lib",
			"glew32s.lib",
			"jsoncpp.lib",
			"freetype.lib",
			"lua53.lib",
			"jsoncpp.lib"
		}

		filter "configurations:Debug"
			symbols "on"
			
		filter "configurations:Release"
			optimize "on"
