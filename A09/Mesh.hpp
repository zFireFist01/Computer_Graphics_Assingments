

/**************
 Creae the meshes, as described below
 
 WARNING!
 Since it is a C program, you can use for loops and functions if you think they can be helpful in your solution.
 However, please include all your code in this file, since it will be put in an automatic correction process
 for the final evaluation. Please also be cautious when using standard libraries and symbols, since they
 might not be available in all the development environments (especially, they might not be available
 in the final evaluation environment, preventing your code from compiling).
 This WARNING will be valid far ALL THE ASSIGNMENTs, but it will not be repeated in the following texts,
 so please remember these advices carefully!
 
***************/

void MakeSquare(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   {-size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f,-size/2.0f,0.0f,1.0f,0.0f},
				   { size/2.0f,0.0f, size/2.0f,0.0f,1.0f,0.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
	float half = size / 2.0f;
	vertices = {
				   {-size/2.0f, -half,-size/2.0f,  1, 1, 1}, // 0
				   {-size/2.0f, -half, size/2.0f,  -1, -1, 1}, // 1
				   { size/2.0f, -half,-size/2.0f,  1, -1, -1}, // 2
				   { size/2.0f, -half, size/2.0f,  1, -1, 1}, // 3
				   {-size/2.0f, half,-size/2.0f,   -1, 1, -1}, // 4
				   {-size/2.0f, half, size/2.0f,   -1, 1, 1}, // 5 
				   { size/2.0f, half,-size/2.0f,   1, 1, -1}, // 6
				   { size/2.0f, half, size/2.0f,   1, 1, 1}}; // 7
	
	indices = {1, 0, 2,    3, 1, 2, 
			   0, 4, 2,    4, 6, 2,
			   7, 3, 2,    6, 7, 2,
			   0, 1, 5,    4, 0, 5,
			   1, 3, 5,    3, 7, 5,
               6, 4, 5,    7, 6, 5};
}

void MakeCylinder(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
    float halfHeight = height / 2.0f;
    float angleStep = 2 * M_PI / slices;

    // Vertici
    for (int i = 0; i <= slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Vertice del cerchio superiore
        vertices.push_back({x, halfHeight, z, x, 0.0f, z});
        // Vertice del cerchio inferiore
        vertices.push_back({x, -halfHeight, z, x, 0.0f, z});
    }

    // Vertici centrali superiore e inferiore
    vertices.push_back({0.0f, halfHeight, 0.0f, 0.0f, 1.0f, 0.0f});
    vertices.push_back({0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f});

    int topCenterIndex = vertices.size() - 2;
    int bottomCenterIndex = vertices.size() - 1;

    // Indici per i lati
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        int top1 = 2 * i;
        int top2 = 2 * next;
        int bottom1 = top1 + 1;
        int bottom2 = top2 + 1;

        indices.push_back(top1);
        indices.push_back(bottom2);
        indices.push_back(bottom1);

        indices.push_back(top1);
        indices.push_back(top2);
        indices.push_back(bottom2);
    }

    // Indici per le basi superiore e inferiore
    for (int i = 0; i < slices; ++i) {
        int next = (i + 1) % slices;
        int top1 = 2 * i;
        int bottom1 = top1 + 1;

        indices.push_back(top1);
        indices.push_back(topCenterIndex);
        indices.push_back(2 * next);

        indices.push_back(bottom1);
        indices.push_back(2 * next + 1);
        indices.push_back(bottomCenterIndex);
    }

}

void MakeCone(float radius, float height, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	float angleStep = 2 * M_PI / slices;
    float halfHeight = height / 2.0f;

    // Vertice superiore
    vertices.push_back({0.0f, halfHeight, 0.0f, 0.0f, 1.0f, 0.0f});
    int topVertexIndex = 0;

    // Vertici del cerchio inferiore
    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float nx = cos(angle); // normale in direzione della posizione x
        float nz = sin(angle); // normale in direzione della posizione z
        vertices.push_back({x, -halfHeight, z, nx, 0.0f, nz});
    }

    // Vertice centrale inferiore
    vertices.push_back({0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f});
    int bottomCenterIndex = vertices.size() - 1;

    // Indici per i lati (triangoli in senso antiorario)
    for (int i = 1; i <= slices; ++i) {
        int next = (i % slices) + 1;
        indices.push_back(topVertexIndex);
        indices.push_back(next);
        indices.push_back(i);
    }

    // Indici per la base inferiore (triangoli in senso antiorario)
    for (int i = 1; i <= slices; ++i) {
        int next = (i % slices) + 1;
        indices.push_back(i);
        indices.push_back(next);
        indices.push_back(bottomCenterIndex);
    }
}

void MakeSphere(float radius, int rings, int slices, std::vector<std::array<float,6>> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a std::array<float,6> element.
// In particular, the first three elements (index 0,1,2) encode the position of the vertex (x in index 0,
// y in index 1, and z in index 2). The second set of three elements (index 3,4,5) encode the direction
// of the normal vector for the considerd vertex (N.x in index 3, N.y in index 4, and N.z in index 5).
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.
	for (int r = 0; r <= rings; ++r) {
        float theta = r * M_PI / rings;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int s = 0; s <= slices; ++s) {
            float phi = s * 2 * M_PI / slices;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;

            vertices.push_back({radius * x, radius * y, radius * z, x, y, z});
        }
    }

    // Indices
    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < slices; j++) {
            int first = (i * (slices + 1)) + j;
            int second = first + slices + 1;

            indices.push_back(first);
            indices.push_back(first + 1);
            indices.push_back(second);

            indices.push_back(first + 1);
            indices.push_back(second + 1);
            indices.push_back(second);
        }
    }
}
