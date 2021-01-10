#include "PracticeEngine.h"
#include "VertexBuffer.h"

VertexBuffer::~VertexBuffer()
{
	SAFE_RELEASE(buffer);
}

void VertexBuffer::SetIA()
{
	DEVICECONTEXT->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
}
