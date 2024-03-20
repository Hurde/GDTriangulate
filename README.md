# GDTriangulate

## Why?

Godot's standard triangulation method for polygons slows down with a large number of points. GDTriangulate, a GDExtension, uses external libraries for faster triangulation.

## How to Use This GDExtension

Assuming some familiarity with GDExtensions and having a compiler and SCons:

### Setup and Compilation

    Clone the repository with submodules:
    git clone --recurse-submodules https://github.com/Hurde/GDTriangulate

    Navigate into the repository:
    cd GDTriangulate

    Compile with SCons:
    scons
    
The GDExtension is in GDTriangulate/demo/bin after compiling.

### Integrating with Your Godot Project

    Create the addon folder in your project:
    mkdir -p your_godot_project/addons/GDTriangulate/

    Create a symlink:
    mklink /D "C:\path\to\your\godot_project\addons\GDTriangulate" "C:\path\to\your\GDTriangulate\demo"

### Using the GDExtension

Once integrated, a new node named "GDTriangulate" appears. Use it to perform fast triangulation:

GDTriangulatenode.triangulate(PackedVector2Array) # Your polygon
