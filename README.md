# GDTriangulate

## Why ?

  As godots regular triangulation method for polygons becomes really slow when you exceed a certain amount of points. 
  I had to come up with a different solution
  This GDExtension uses (any) external library to perform a way faster triangulation.

## Howto use this GDExtension?

  Assuming you you know a little of creating a GDExtension.
  Have a compiler and scons ready.
  You can follow these steps to get this GDExtension working.

  1. Clone the repository: git clone --recurse-submodules https://github.com/Hurde/GDTriangulate
  2. CD into the repo: cd GDTriangulate
  3. run scons: scons

  This will compile the GDExtension and can eventually been found in GDTriangulate/demo/bin

  There are a couple ways to add the GDExtension to godot.
  But what i did was to Symlink the folder into the Godot project
  
  1. Create the GDTriangulate addon folder in your godot project: godot_project\addons\GDTriangulate\
  2. Symlink the folders: mklink /D "C:\path\to\your\godot_project\addons\GDTriangulate" "C:\path\to\your\GDTriangulate\demo"
  3. Modify the

  Thats it. if done right you'll see a new node called "GDTriangulate" and be able to use the triangulation method.
  GDTriangulatenode.triangulate(PackedVector2Array) < your polygon
 
