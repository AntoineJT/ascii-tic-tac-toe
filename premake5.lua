-- premake5.lua
workspace "ASCII TicTacToe"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64" }

project "ASCII TicTacToe"
   kind "ConsoleApp"
   language "C"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.c" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   filter "platforms:Win32"
      system "Windows"
      architecture "x32"

  filter "platforms:Win64"
      system "Windows"
      architecture "x64"
