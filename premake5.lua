-- premake5.lua

workspace "RaavanaEngine2.0"

configurations { "Debug", "Release" }
platforms { "Windows" }
architecture "x64"
cppdialect "C++17"
startproject "Sandbox"

filter "system:Windows"
   systemversion "latest"



project "Sandbox"

   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

   includedirs {  "RaavanaEngine2.0/src", }
   links {"RaavanaEngine2.0"}

   files {  "Sandbox/src/**.h",
            "Sandbox/src/**.cpp" 
         }
   
   removefiles { "Sandbox/res/**.*" }

   defines { "RE_IMPORT_DLL"}

   filter "configurations:Debug"
      defines { "RE_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RE_RELEASE" }
      optimize "On"



project "RaavanaEngine2.0"

   location "RaavanaEngine2.0"
   kind "SharedLib"
   language "C++"

   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

   includedirs {  "RaavanaEngine2.0/vendor/SFML/include",
                  "RaavanaEngine2.0/src"}
   libdirs {   "RaavanaEngine2.0/vendor/SFML/lib" }


   files {  "RaavanaEngine2.0/src/**.h",
            "RaavanaEngine2.0/src/**.cpp"
         }

   removefiles{  }

   defines { "SFML_STATIC", "RE_EXPORT_DLL" }
   
   postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}/Sandbox" }

   filter "configurations:Debug"
      defines { "RE_DEBUG" }
      symbols "On"

      links {  "opengl32.lib",
               "openal32.lib",
               "freetype.lib",
               "winmm.lib",
               "gdi32.lib",
               "flac.lib",
               "vorbisenc.lib",
               "vorbisfile.lib",
               "vorbis.lib",
               "ogg.lib",
               "ws2_32.lib",
               "sfml-graphics-s-d.lib",
               "sfml-window-s-d.lib",
               "sfml-system-s-d.lib",
               "sfml-audio-s-d.lib",
               "sfml-network-s-d.lib"
            }

      
      filter "configurations:Release"
      defines { "RE_RELEASE" }
      optimize "On"
      
      links {  "opengl32.lib",
               "openal32.lib",
               "freetype.lib",
               "winmm.lib",
               "gdi32.lib",
               "flac.lib",
               "vorbisenc.lib",
               "vorbisfile.lib",
               "vorbis.lib",
               "ogg.lib",
               "ws2_32.lib",
               "sfml-graphics-s.lib",
               "sfml-window-s.lib",
               "sfml-system-s.lib",
               "sfml-audio-s.lib",
               "sfml-network-s.lib"
            }
      


