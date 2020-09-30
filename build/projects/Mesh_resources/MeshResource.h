#pragma once
class MeshResource
{
	struct vertex
	{
		float position[3];
		float color[4];
	};

	MeshResource();

	void vertexBuffer(vertex v[], int size);
	void indexBuffer(unsigned int ibuf[], int size);

	void render();
};

