//
// Created by datalink on 28.01.2017.
//
#include "NativeRenderer.h"
#include "macro.h"
#include "GLHelpers.h"
#include <string.h>

const char vshader[] = ""
"uniform mat4 u_MVPMatrix;"
"attribute vec4 a_Position;\n"
"void main(){\n"
"    gl_Position = u_MVPMatrix * a_Position;\n"
"}";

const char tshader[] = ""
"precision mediump float;\n"
"uniform vec4 u_Color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = u_Color;\n"
"}";

NativeRenderer::NativeRenderer() {
    DCALL();
}

void NativeRenderer::Init() {
    DCALL();
    DSTR(glGetString(GL_VERSION));
    DSTR(glGetString(GL_SHADING_LANGUAGE_VERSION));
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    auto prog = GLHelpers::BuildProgram(vshader, strlen(vshader), tshader, strlen(tshader));
    GLHelpers::ValidateProgram(prog);
}

void NativeRenderer::Draw() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


