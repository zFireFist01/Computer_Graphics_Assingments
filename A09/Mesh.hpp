

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
        {-half, -half,  half,  0.0f,  0.0f,  1.0f}, 
        { half, -half,  half,  0.0f,  0.0f,  1.0f}, 
        {-half,  half,  half,  0.0f,  0.0f,  1.0f}, 
        { half,  half,  half,  0.0f,  0.0f,  1.0f}, 

        { half, -half, -half,  0.0f,  0.0f, -1.0f}, 
        {-half, -half, -half,  0.0f,  0.0f, -1.0f}, 
        { half,  half, -half,  0.0f,  0.0f, -1.0f}, 
        {-half,  half, -half,  0.0f,  0.0f, -1.0f}, 

        {-half, -half, -half, -1.0f,  0.0f,  0.0f}, 
        {-half, -half,  half, -1.0f,  0.0f,  0.0f}, 
        {-half,  half, -half, -1.0f,  0.0f,  0.0f}, 
        {-half,  half,  half, -1.0f,  0.0f,  0.0f}, 

        { half, -half,  half,  1.0f,  0.0f,  0.0f}, 
        { half, -half, -half,  1.0f,  0.0f,  0.0f}, 
        { half,  half,  half,  1.0f,  0.0f,  0.0f}, 
        { half,  half, -half,  1.0f,  0.0f,  0.0f}, 

        {-half,  half,  half,  0.0f,  1.0f,  0.0f}, 
        { half,  half,  half,  0.0f,  1.0f,  0.0f}, 
        {-half,  half, -half,  0.0f,  1.0f,  0.0f}, 
        { half,  half, -half,  0.0f,  1.0f,  0.0f}, 

        {-half, -half, -half,  0.0f, -1.0f,  0.0f}, 
        { half, -half, -half,  0.0f, -1.0f,  0.0f}, 
        {-half, -half,  half,  0.0f, -1.0f,  0.0f}, 
        { half, -half,  half,  0.0f, -1.0f,  0.0f}};

    indices = {
        0, 1, 2,   1, 3, 2,
        4, 5, 6,   5, 7, 6,
        8, 9, 10,  9, 11, 10,
        12, 13, 14, 13, 15, 14,
        16, 17, 18, 17, 19, 18,
        20, 21, 22, 21, 23, 22};
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
    float angleStep = 2.0f * 3.14159265f / slices;

    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Bottom vertex
        vertices.push_back({x, -halfHeight, z, x, 0.0f, z});
		vertices.push_back({x, -halfHeight, z, 0.0f, -1.0f, 0.0f});
        
        // Top vertex
        vertices.push_back({x, halfHeight, z, x, 0.0f, z});
		vertices.push_back({x, halfHeight, z, 0.0f, 1.0f, 0.0f});
    }

    vertices.push_back({0.0f, -halfHeight, 0.0f, 0.0f, -1.0f, 0.0f});
    
    vertices.push_back({0.0f, halfHeight, 0.0f, 0.0f, 1.0f, 0.0f});
    
    int baseIndex = vertices.size() - 2;

    // Indices for the side of the cylinder
    for (int i = 0; i < slices; ++i) {
        int bottomIndex = 4 * i;
        int topIndex = 4 * i + 2;
        int nextBottomIndex = (4 + 4 * i) % (4 * slices);
        int nextTopIndex = (4 + (4 * i + 2)) % (4 * slices);

        indices.push_back(bottomIndex);
        indices.push_back(topIndex);
        indices.push_back(nextBottomIndex);

        indices.push_back(topIndex);
        indices.push_back(nextTopIndex);
        indices.push_back(nextBottomIndex);
    }

    for (int i = 0; i < slices; ++i) {
        indices.push_back(baseIndex);
		indices.push_back(4 * i + 1); 
        indices.push_back((4 + 4 * i + 1) % (4 * slices));
    }

    for (int i = 0; i < slices; ++i) {
        indices.push_back(baseIndex + 1);
		indices.push_back((4 + 4 * i + 3) % (4 * slices));
        indices.push_back(4 * i + 3);
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
	float halfHeight = height / 2.0f;
    float angleStep = 2.0f * 3.14159265f / slices;

    for (int i = 0; i < slices; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        vertices.push_back({x, -halfHeight, z, x, 0.0f, z});
		vertices.push_back({x, -halfHeight, z, 0.0f, -1.0f, 0.0f});
    }

	vertices.push_back({0, halfHeight, 0, 0, 0.0f, 0});
	vertices.push_back({0, -halfHeight, 0, 0, -1.0f, 0});

	for (int i = 0; i < slices; ++i) {
        int bottomIndex = 2 * i;
        int nextBottomIndex = (2 + 2 * i) % (2 * slices);

        indices.push_back(bottomIndex);
        indices.push_back(vertices.size() - 2);
        indices.push_back(nextBottomIndex);
    }

	for (int i = 0; i < slices; ++i) {
        indices.push_back(vertices.size() - 1);
		indices.push_back(2 * i + 1); 
        indices.push_back((2 + 2 * i + 1) % (2 * slices));
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
	for(int i = 0; i <= rings; i++){
		float theta = M_PI * (float) i / (float) rings - M_PI / 2;
		for(int j = 0; j < slices; j++){
			float ang = 2 * M_PI * (float) j / (float) slices;
			vertices.push_back({radius * cos(ang) * cos(theta), radius * sin(theta), radius * sin(ang) * cos(theta),
								radius * cos(ang) * cos(theta), radius * sin(theta), radius * sin(ang) * cos(theta)});
		}
	}

	for(int i = 0; i < rings; i++){
		for(int j = 0; j < slices; j++){
			indices.push_back(i * slices + j);
			indices.push_back((i + 1) * slices + j);
			indices.push_back((j + 1) % slices + (i * slices));

			indices.push_back((i + 1) * slices + j);
			indices.push_back((j+1) % slices + ((i + 1) * slices));
			indices.push_back((j + 1) % slices + (i * slices));
		}
	}
}
