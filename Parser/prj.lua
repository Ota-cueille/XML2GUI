project("parser")
    kind("ConsoleApp")
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
