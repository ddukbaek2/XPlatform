cmake_minimum_required (VERSION 3.27.5)
project(XPlatform LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
add_executable(XPlatform, XPlatform.cpp)

#add_executable (XPlatform "XPlatform.cpp" "XPlatform.h")
#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET XPlatform PROPERTY CXX_STANDARD 20)
#endif()