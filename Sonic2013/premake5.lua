project("Sonic2013")
    language("C++")
    cppdialect("C++11")
    targetdir("bin/%{cfg.platform}/%{cfg.buildcfg}")
    runpathdirs("bin/%{cfg.platform}/%{cfg.buildcfg}")
    kind("WindowedApp")

    -- Platform-Specifics
    if Target == "windows" then
        defines("NOMINMAX")
    end
    
    includedirs({ "../depends", "../depends/criware/include", "../Library/cslib/include", "src" })
    files({ "src/**.cpp", "src/**.h", "../depends/lua/**.c", "../depends/lua/**.cpp" })

    links("cslib")
    links("d3d9.lib")

    -- TODO: REPLACE CRIWARE WITH SOMETHING OPEN-SOURCE PLEASE LOL
    links("../depends/criware/libs/%{cfg.platform}/CriwareWrapper.lib")
    --links("../depends/criware/libs/%{cfg.platform}/cri_base_pc%{cfg.platform}D.lib")
    --links("../depends/criware/libs/%{cfg.platform}/cri_file_system_pc%{cfg.platform}D.lib")
    
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
