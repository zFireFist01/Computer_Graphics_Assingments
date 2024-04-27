

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

void MakeSquare(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a square, on the xz-plane, aligned with the axis, and centered in the origin.
// The length of the four sides is in parameter >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: this procedure has already been implemented. You can keep it as is
	vertices = {
				   {-size/2.0f,0.0f,-size/2.0f},
				   {-size/2.0f,0.0f, size/2.0f},
				   { size/2.0f,0.0f,-size/2.0f},
				   { size/2.0f,0.0f, size/2.0f}};
	indices = {0, 1, 2,    1, 3, 2};
}

void MakeCube(float size, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cube, with the faces perpendicular to the axis, and centered in the origin.
// The length of one edge of the cube is >size<.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a square. You can use it as a side of the cube (please remember
// to change the value of the y component, otherwise the result will be wrong
	
	float half = size / 2.0f;
	vertices = {
				   {-size/2.0f, -half,-size/2.0f}, // 0
				   {-size/2.0f, -half, size/2.0f}, // 1
				   { size/2.0f, -half,-size/2.0f}, // 2
				   { size/2.0f, -half, size/2.0f}, // 3
				   {-size/2.0f, half,-size/2.0f}, // 4
				   {-size/2.0f, half, size/2.0f}, // 5 
				   { size/2.0f, half,-size/2.0f}, // 6
				   { size/2.0f, half, size/2.0f}}; // 7
	indices = {1, 0, 2,    3, 1, 2, 
			   0, 4, 2,    4, 6, 2,
			   7, 3, 2,    6, 7, 2,
			   0, 1, 5,    4, 0, 5,
			   1, 3, 5,    3, 7, 5,
               6, 4, 5,    7, 6, 5};

}

void MakeCylinder(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cylinder, approximated by a prism with a base composed by a regular polygon with >slices< sides.
// The radius of the cylinder is >radius<, and it height is >height<. The cylinder has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The top and bottom caps are are aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a rectangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	
	
	float halfHeight = height / 2.0f;
	int numVertices = 2 * (slices + 1);  // slices + 1 for top and bottom
	vertices.clear();
	vertices.resize(numVertices);
	indices.clear();

	// Generate vertices for the bottom and top circles
	for (int i = 0; i < slices; i++) {
		float ang = 2 * M_PI * (float)i / (float)slices;
		vertices[i] = glm::vec3(radius * cos(ang), -halfHeight, radius * sin(ang));
		vertices[i + slices + 1] = glm::vec3(radius * cos(ang), halfHeight, radius * sin(ang));
		
		int next = (i + 1) % slices;


		// Side faces
		indices.push_back(i);
		indices.push_back(i + slices + 1);
		indices.push_back(next + slices + 1);

		indices.push_back(i);
		indices.push_back(next + slices + 1);
		indices.push_back(next);


		// Top cap - the vertices should be wound CCW as viewed from above
		indices.push_back(slices + 1); // center top vertex
		indices.push_back(next + slices + 2); // next top vertex
		indices.push_back(i + slices + 2); // current top vertex

		// Bottom cap - the vertices should be wound CCW as viewed from below
		indices.push_back(0); // center bottom vertex
		indices.push_back(i + 1); // current bottom vertex
		indices.push_back(next + 1); // next bottom vertex
	}

}

void MakeCone(float radius, float height, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices) {
// Creates a cone, approximated by a pyramid with a base composed by a regular polygon with >slices< sides.
// The radius of the cone is >radius<, and it height is >height<. The cone has its centere
// in the origin, and spans half above and half below the plane that passes thorugh the origin.
// The bottom cap is aligned with xz-plane and perpendicular to the y-axis.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a triangle. You have to change it, or you will obtain a wrong result
// You should use a for loop, and you should start from the procedure to create a circle seen during the lesson
	float halfHeight = height / 2.0f;
	vertices.clear();
	vertices.resize(slices + 2); // slices + 1 for the base + 1 for the tip
	indices.clear();

	// Tip of the cone
	vertices[0] = glm::vec3(0.0f, halfHeight, 0.0f);

	// Base vertices
	for (int i = 0; i < slices; i++) {
		float angle = 2 * M_PI * i / slices;
		float x = radius * cos(angle);
		float z = radius * sin(angle);
		vertices[i + 1] = glm::vec3(x, -halfHeight, z);
	}

	// Base center (for easy cap triangulation)
	vertices[slices + 1] = glm::vec3(0.0f, -halfHeight, 0.0f);


	for (int i = 1; i <= slices; i++) {
		int next = (i % slices) + 1;

		// Side face
		indices.push_back(0);  
		indices.push_back(next);
		indices.push_back(i);

		// Base cap
		indices.push_back(slices + 1);
		indices.push_back(i);
		indices.push_back(next);
	}

}

void MakeSphere(float radius, int rings, int slices, std::vector<glm::vec3> &vertices, std::vector<uint32_t> &indices)
{
// Creates a sphere, approximated by a poliedron composed by >slices<, and >rings< rings.
// The radius of the sphere is >radius<, and it is centered in the origin.
// The procedure should fill the array contained in the >vertices< parameter, with the positions of
// the vertices of the primitive, expressed with their local coordinates in a glm::vec3 element. 
// Indices should be returned in the >indices< array, starting from 0, and up to vertices.size()-1.
// The primitive is encoded as an indexed triangle list, so the size of the >indices< array, should
// be a multiple of 3: each group of three indices, defines a different triangle.
//
// HINT: the procedure below creates a circle. You have to change it, or you will obtain a wrong result
// You should use two nested for loops, one used to span across the rings, and the other that spans along
// the rings.


	for (int i = 0; i <= rings; i++) {
		float phi = M_PI * i / rings;
		for (int j = 0; j <= slices; j++) {
			float theta = 2 * M_PI * j / slices;
			float x = radius * sin(phi) * cos(theta);
			float y = radius * cos(phi);
			float z = radius * sin(phi) * sin(theta);
			vertices.push_back(glm::vec3(x, y, z));
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
