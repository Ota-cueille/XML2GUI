workspace("xml2gui")

    configurations({
        "release",
        "debug"
    })

    system("windows")

    filter("configurations:release")
	    defines({ "RELEASE" })
	    optimize("On")
    filter("configurations:debug")
	    defines({ "DEBUG" })
	    symbols("On")

paths = {}
dependencyFolder = "../../../Libraries/cpp/" -- must be relative to this file
buildFolder = "build/%{prj.name}/%{cfg.buildcfg}/" -- also relative to this file

-- list of the dependencies
group("dependencies")
    -- glfw
    include("glfw/dep.lua")
    -- glad
    include("glad/dep.lua")
    -- stb_image
    -- boost ?
group("")

-- the xml2gui command tool
include("Parser/prj.lua")

-- the xml2gui library
include("GuiRenderer/prj.lua")
