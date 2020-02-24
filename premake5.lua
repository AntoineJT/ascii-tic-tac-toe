-- premake5.lua
workspace "ASCII TicTacToe"
   configurations { "Debug", "Release" }

project "ASCII TicTacToe - Bin"
   kind "ConsoleApp"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.c" }
   removefiles { "tests/**", "src/vendor/bdd-for-c.h" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "ASCII TicTacToe - Tests"
	kind "ConsoleApp"
	language "C"
	targetdir "bin/%{cfg.buildcfg}"
	
	files { "**.h", "**.c" }
	removefiles { "src/main.c" }
	
	   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
	  