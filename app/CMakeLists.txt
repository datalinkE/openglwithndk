# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

include_directories( src/main/cpp/src )

add_library( native-lib
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/jni-calls.cpp
             src/main/cpp/src/AndroidPlatform.cpp
             src/main/cpp/src/NativeRenderer.cpp )

find_library( log-lib
              log )

find_library( gl-lib
              GLESv2 )

target_link_libraries(  native-lib
                       ${log-lib}
                       ${gl-lib} )
