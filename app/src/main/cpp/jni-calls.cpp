#include <jni.h>
#include <string>
#include "macro.h"

extern "C"
JNIEXPORT void JNICALL
Java_tk_datalinke_openglwithndk_GameSurfaceView_on_1surface_1created(JNIEnv *env, jclass type) {
    DCALL();
}

extern "C"
JNIEXPORT void JNICALL
Java_tk_datalinke_openglwithndk_GameSurfaceView_on_1surface_1changed(JNIEnv *env, jclass type,
                                                                  jint width, jint height) {
    DCALL();
}

extern "C"
JNIEXPORT void JNICALL
Java_tk_datalinke_openglwithndk_GameSurfaceView_on_1draw_1frame(JNIEnv *env, jclass type) {
    DCALL();
}

extern "C"
jstring
Java_tk_datalinke_openglwithndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    DCALL();
    std::string hello = "Hello from C++";
    DEBUG(hello.c_str());
    DEBUGF("varadic %s", "argument");
    return env->NewStringUTF(hello.c_str());
}
