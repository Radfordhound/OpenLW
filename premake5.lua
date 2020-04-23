workspace("OpenLW")
    configurations({ "Debug", "Release" })
    platforms({ "x86", "x64" })

    -- Disable some warnings on windows
    if os.target() == "windows" then
        disablewarnings("4996") -- please use wcscpy_s even though it's not in the C++ standard we're begging you
    end
    
include("Library/cslib")
include("Sonic2013")
