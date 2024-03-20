#include "GDTriangulate.h"
#include <earcut.hpp/include/mapbox/earcut.hpp>
// #include <delaunator-cpp/include/delaunator.hpp>

void GDTriangulate::_bind_methods() {
    ClassDB::bind_method(D_METHOD("add_polygon", "polygon"), &GDTriangulate::add_polygon);
    ClassDB::bind_method(D_METHOD("draw_mesh"), &GDTriangulate::draw_mesh);
    ClassDB::bind_method(D_METHOD("triangulate", "pointsArray"), &GDTriangulate::triangulate);
}


GDTriangulate::GDTriangulate() {
    // Constructor
}

GDTriangulate::~GDTriangulate() {
    //DeConstructor
    allIndices.clear();
    allVertices.clear();
}

void GDTriangulate::add_polygon(const PackedVector2Array& polygon) {

    auto [vertices, indices] = triangulate(polygon);

    int offset = allVertices.size();
    for (int i = 0; i < indices.size(); ++i) {
        allIndices.push_back(indices[i] + offset); 
    }

    allVertices.append_array(vertices);
}

MeshInstance2D* GDTriangulate::draw_mesh() {

    if (allVertices.size() > 0 && allIndices.size() > 0) {
        Ref<ArrayMesh> mesh = create_mesh_from_polygon(allVertices, allIndices);

        allVertices.clear();
        allIndices.clear();

        MeshInstance2D* meshInstance = memnew(MeshInstance2D);
        meshInstance->set_mesh(mesh);
        add_child(meshInstance);

        return meshInstance;
    }
    return nullptr;
}

Ref<ArrayMesh> GDTriangulate::create_mesh_from_polygon(const PackedVector2Array& vertices, const PackedInt32Array& indices) {
    Ref<ArrayMesh> mesh = memnew(ArrayMesh);

    Array arrays;
    arrays.resize(ArrayMesh::ARRAY_MAX);
    arrays[ArrayMesh::ARRAY_VERTEX] = vertices;
    arrays[ArrayMesh::ARRAY_INDEX] = indices;

    mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, arrays);

    return mesh; 
}

using Point = std::array<double, 2>;
using N = uint32_t;

// Here happens the actual triangulation
std::pair<PackedVector2Array, PackedInt32Array> GDTriangulate::triangulate(const PackedVector2Array& pointsArray) {
    std::vector<Point> vertices;
    
    for (int i = 0; i < pointsArray.size(); ++i) {
        Vector2 point = pointsArray[i];
        vertices.push_back({point.x, point.y});
    }

    std::vector<std::vector<Point>> polygon = {vertices};
    
    // Perform triangulation
    auto indices = mapbox::earcut<N>(polygon);

    PackedVector2Array outputVertices;
    PackedInt32Array outputIndices;

    for (const auto& vertex : vertices) {
        outputVertices.push_back(Vector2(vertex[0], vertex[1]));
    }
    
    for (const auto& index : indices) {
        outputIndices.push_back(index);
    }

    return std::make_pair(outputVertices, outputIndices);
}

