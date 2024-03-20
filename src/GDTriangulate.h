#ifndef GDTRIANGULATE_H
#define GDTRIANGULATE_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/mesh_instance2d.hpp>
#include <godot_cpp/classes/array_mesh.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>
#include <godot_cpp/variant/packed_int32_array.hpp>

#include <vector>

using namespace godot;

class GDTriangulate : public Node2D {
    GDCLASS(GDTriangulate, Node2D);

private:
    Array allVertices;
    Array allIndices;

protected:
    static void _bind_methods();

public:
    GDTriangulate();
    ~GDTriangulate();

    void add_polygon(const PackedVector2Array& polygon);
    Ref<ArrayMesh> create_mesh_from_polygon(const PackedVector2Array& vertices, const PackedInt32Array& indices);
    MeshInstance2D* draw_mesh();
    std::pair<PackedVector2Array, PackedInt32Array> triangulate(const PackedVector2Array& pointsArray);
};

#endif // GDTRIANGULATE_H
