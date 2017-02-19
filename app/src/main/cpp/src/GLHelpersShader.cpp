#include "GLHelpers.h"

#include <string>
#include <assert.h>
#include "platform.h"
#include "macro.h"

namespace GLHelpers
{
	std::string shaderInfoLog(GLuint shaderObjectId) {
		DCALL();
	    DINT(shaderObjectId);
		GLint logLength = 0;

		glGetShaderiv(shaderObjectId, GL_INFO_LOG_LENGTH, &logLength);
		DINT(logLength);

        char log_buffer[100];
		glGetShaderInfoLog(shaderObjectId, (logLength > 100 ? 100 : logLength), &logLength, (GLchar*)log_buffer);
		DINT(logLength);

		return std::string(log_buffer, logLength);
	}

	std::string programInfoLog(GLuint programObjectId) {
		DCALL();
	    DINT(programObjectId);
		GLint logLength = 0;
		glGetProgramiv(programObjectId, GL_INFO_LOG_LENGTH, &logLength);
		DINT(logLength);

		char log_buffer[100];
		glGetProgramInfoLog(programObjectId, (logLength > 100 ? 100 : logLength), &logLength, (GLchar*)log_buffer);
		DINT(logLength);
		return std::string(log_buffer, logLength);
	}

	GLuint compileShader(const GLenum type, const GLchar *source, const GLint length) {
	    DCALL();
	    assert(source != NULL);
	    GLuint shaderObjectId = glCreateShader(type);
	    GLint compileStatus;

	    assert(shaderObjectId != 0);

	    glShaderSource(shaderObjectId, 1, (const GLchar **)&source, &length);
	    glCompileShader(shaderObjectId);
	    glGetShaderiv(shaderObjectId, GL_COMPILE_STATUS, &compileStatus);

		DINT(compileStatus);
        if (compileStatus != GL_TRUE) {
            DCSTR(shaderInfoLog(shaderObjectId));
        }

	    assert(compileStatus == GL_TRUE);

	    return shaderObjectId;
	}

	GLuint linkProgram(const GLuint vertex_shader, const GLuint fragment_shader) {
	    DCALL();
	    GLuint programObjectId = glCreateProgram();
	    GLint linkStatus;

	    assert(programObjectId != 0);

	    glAttachShader(programObjectId, vertex_shader);
	    glAttachShader(programObjectId, fragment_shader);
	    glLinkProgram(programObjectId);
	    glGetProgramiv(programObjectId, GL_LINK_STATUS, &linkStatus);

	    DINT(linkStatus);
        if (linkStatus != GL_TRUE) {
            DCSTR(programInfoLog(programObjectId));
        }

        assert(linkStatus == GL_TRUE);

        DINT(programObjectId);
	    return programObjectId;
	}

	GLuint BuildProgram(
	    const GLchar * vertexShaderSource, const GLint vertexShaderSourceLength,
	    const GLchar * fragmentShaderSource, const GLint fragmentShaderSourceLength) {
	    DCALL();
	    assert(vertexShaderSource != NULL);
	    assert(fragmentShaderSource != NULL);

	    GLuint vertexShader = compileShader(
                GL_VERTEX_SHADER, vertexShaderSource, vertexShaderSourceLength);
	    GLuint fragmentShader = compileShader(
                GL_FRAGMENT_SHADER, fragmentShaderSource, fragmentShaderSourceLength);

	    DEBUG("Success");
        DINT(vertexShader);
        DINT(fragmentShader);
	    return linkProgram(vertexShader, fragmentShader);
	}

	GLint ValidateProgram(const GLuint program) {
	    DCALL();
        int validateStatus;
        glValidateProgram(program);
        glGetProgramiv(program, GL_VALIDATE_STATUS, &validateStatus);

        DINT(validateStatus);
        if (validateStatus != GL_TRUE) {
            DCSTR(programInfoLog(program));
        }

        return validateStatus;
	}
}

