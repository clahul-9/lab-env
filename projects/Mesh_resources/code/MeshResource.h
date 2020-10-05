#pragma once
class MeshResource
{
public:
	struct vertex
	{
		float position[3];
		float color[4];
	};

	MeshResource();

	int vertexBuffer(vertex v[], int size);
	void indexBuffer(unsigned int ibuf[], int size);

	void draw(int size, int vbo, int progran);
};

