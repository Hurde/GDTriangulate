#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

GDExtension_name = 'gdtriangulate'

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
env.Append(CPPPATH=["src/earcut.hpp/include/mapbox"]) # Your custom triangulation library
#env.Append(CPPPATH=["src/my/custom/library"])    # If you want to use more custom libraries, append them here.
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/{}.{}.{}.framework/{}.{}.{}".format(
            GDExtension_name, env["platform"], env["target"], GDExtension_name, env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demo/bin/{}{}{}".format(GDExtension_name, env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
