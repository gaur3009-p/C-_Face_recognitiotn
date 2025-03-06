cmake_minimum_required(VERSION 3.10)
project(FaceRecognitionWebGL)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_library(UWS_LIB uWS)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(server src/server.cpp)
add_executable(face_detect src/face_detect.cpp)
add_executable(webgl src/webgl.cpp)

target_link_libraries(server ${UWS_LIB})
target_link_libraries(face_detect ${OpenCV_LIBS} ${UWS_LIB})
target_link_libraries(webgl OpenGL::GL glfw)
