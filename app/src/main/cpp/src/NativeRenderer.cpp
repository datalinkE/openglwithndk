//
// Created by datalink on 28.01.2017.
//
#include <sstream>
#include "NativeRenderer.h"
#include "macro.h"

NativeRenderer::NativeRenderer() {
    DCALL();
}

void NativeRenderer::Init() {
    DCALL();
    std::ostringstream versionString;
    versionString << glGetString(GL_VERSION) << ", " << glGetString(GL_SHADING_LANGUAGE_VERSION);
    auto glesVersionInfo = versionString.str();
    DEBUG(glesVersionInfo.c_str());
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void NativeRenderer::Draw() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


