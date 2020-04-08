project("cslib")
    language("C++")
    cppdialect("C++11")
    targetname("csl")
    targetdir("bin/%{cfg.platform}/%{cfg.buildcfg}")
    runpathdirs("bin/%{cfg.platform}/%{cfg.buildcfg}")
    kind("StaticLib")

    -- Platform-Specifics
    if Target == "windows" then
        defines("NOMINMAX")
    end
    
    includedirs({ "include" })
    files({ "src/**.cpp", "src/**.h", "include/**.h" })
    
    -- MSC Optimization
    filter("toolset:msc")
        flags("MultiProcessorCompile")

    -- Debug Configuration
    filter("configurations:Debug*")
        defines("DEBUG")
        symbols("On")

    -- Release Configuration
    filter("configurations:Release*")
        defines("NDEBUG")
        optimize("Speed")
        flags("LinkTimeOptimization")
        
    -- x86
    filter("platforms:x86")
        architecture("x86")
        defines("x86")
        
    -- x64
    filter("platforms:x64")
        architecture("x86_64")
        defines("x64")
