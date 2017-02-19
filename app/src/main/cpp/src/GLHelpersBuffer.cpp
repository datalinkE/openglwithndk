#include "GLHelpers.h"

#include <assert.h>
#include "platform.h"
#include "macro.h"

namespace GLHelpers
{
	GLuint CreateVBO(const GLsizeiptr size, const GLvoid *data, const GLenum usage)
	{
	    DCALL();
	    assert(data != NULL);
		GLuint vboObject;
		glGenBuffers(1, &vboObject);
		assert(vboObject != 0);

		glBindBuffer(GL_ARRAY_BUFFER, vboObject);
		glBufferData(GL_ARRAY_BUFFER, size, data, usage);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		DINT(vboObject);
		DINT(size);
		return vboObject;
	}
}
