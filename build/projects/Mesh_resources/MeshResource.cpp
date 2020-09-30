#include "MeshResource.h"
#include "GL/glew.h"

void MeshResource::vertexBuffer(vertex v[], int size) {
	float *buf = new float[size];
	buf[]=(float) v[];
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
}