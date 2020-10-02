#include "MeshResource.h"
#include "GL/glew.h"

MeshResource::MeshResource(){}

int MeshResource::vertexBuffer(vertex v[], int size) {
	
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	unsigned int buffersize = sizeof(float)*7 * size;
	glBufferData(GL_ARRAY_BUFFER, buffersize, (float*) v, GL_STATIC_DRAW);

	return vbo;
}
void MeshResource::indexBuffer(unsigned int buf[], int size) {
	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	unsigned int bufferSize = sizeof(unsigned int) * size;
}