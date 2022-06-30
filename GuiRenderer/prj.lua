project("renderer")
    kind("StaticLib")
    language("C++")
    cppdialect("C++20")

    objdir("../" .. buildFolder .. "obj/")
    targetdir("../" .. buildFolder)

    includedirs({
        "include/"
    })

    files({
        "source/**.cpp",
        "source/**.c"
    })
