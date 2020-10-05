#include "MeshResource.h"
#include "GL/glew.h"

MeshResource::MeshResource(){}

int MeshResource::vertexBuffer(vertex v[], int size) {
	
	unsigned int vbo;
	glGenBuffers(0, &vbo);
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
void MeshResource::draw(int size, int vbo,int program) {

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glUseProgram(program);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, nullptr);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (GLvoid*)(sizeof(float) * 3));
	glDrawArrays(GL_TRIANGLES, 0, size);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}