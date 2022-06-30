<link rel="stylesheet" href="./style.css">

# XML2GUI
static markup language gui

# Build

We use Premke5 to create our Makefiles:  

- You can download [premake](https://premake.github.io/) from their website, it's a lightweight build configuration.  
- Then put the `premake5.exe` in the **xml2gui** <underline>root</underline> folder.  
- Once you have installed premake you just have to generate your favorite build tool configuration files with premake:
    - open a terminal in the **xml2gui** folder  
    - use `premake5.exe` with one of it's prebuild options to generate your project architecture (`vs2017`, `vs2019`, `vs2022`, `xcode4`, `codelite`, `gmake2`)
- now you are ready to modify, build and run this library, *`enjoy`* !
