#pragma once

#include <GLES2/gl2.h>

namespace GLHelpers
{
	GLuint CreateVBO(const GLsizeiptr size, const GLvoid *data, const GLenum usage);

	GLuint BuildProgram(
			const GLchar * vertexShaderSource, const GLint vertexShaderSourceLength,
			const GLchar * fragmentShaderSource, const GLint fragmentShaderSourceLength);

	/* Should be called just before using a program to draw, if validation is needed. */
	GLint ValidateProgram(const GLuint program);
}

#define BUFFER_OFFSET(i) ((void*)(i))
