workspace("xml2gui")

    -- architexture is x86_64

    configurations({
        "release",
        "debug"
    })

    system({
        "windows",
        "linux"
    })

    filter("configurations:release")
	    defines({ "RELEASE" })
	    optimize("On")
    filter("configurations:debug")
	    defines({ "DEBUG" })
	    symbols("On")
    filter {}

paths = {}
dependencyFolder = "../../../Libraries/cpp/" -- must be relative to this file
buildFolder = "build/%{prj.name}/%{cfg.buildcfg}/" -- also relative to this file

-- list of the dependencies
group("dependencies")
    -- glfw
    -- glad
    -- glm
    -- stb_image
    -- boost ?
group {}

-- the xml2gui command tool
project("./Parser/prj.lua")

-- the xml2gui library
project("./GuiRenderer/prj.lua")
