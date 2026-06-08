cmake_minimum_required(VERSION 3.10)

project(app C)

if (!MSVC)
    message(FATAL_ERROR "Only MSVC is supported")
endif()

# Options
option(ENABLE_CRTDBG "Enable CRTDBG when -DCMAKE_BUILD_TYPE=Debug" OFF)
option(ENABLE_ASAN "Enable ASan when -DCMAKE_BUILD_TYPE=Debug" OFF)

if (ENABLE_CRTDBG AND ENABLE_ASAN)
    message(FATAL_ERROR "ENABLE_CTRDBG and ENABLE_ASAN cannot be used at the same time")
endif()

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Do not use default cmake flags
set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

#####################################################
# Common
#####################################################
target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE
    /utf-8 -Oi -fp:precise -MP -FC -GF)
target_compile_options(${PROJECT_NAME} PRIVATE
    -W4 -wd4127 -wd4146 -wd4505 -wd4456 -wd4457)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    UNICODE _UNICODE _CRT_SECURE_NO_WARNINGS)
# target_include_directories(${PROJECT_NAME} PRIVATE 
#     ${CMAKE_SOURCE_DIR}/vendor/raylib/include)
# target_link_options(${PROJECT_NAME} PRIVATE
#     /libpath:${CMAKE_SOURCE_DIR}/vendor/raylib/lib)
# target_link_libraries(${PROJECT_NAME} PRIVATE raylib.lib winmm.lib)

#####################################################
# Debug
#####################################################
target_compile_options(${PROJECT_NAME} PRIVATE 
    $<$<CONFIG:Debug>: -Od -MDd -Zi>)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG _DEBUG>)
if (ENABLE_CRTDBG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:ENABLE_CRTDBG>)
endif()
if (ENABLE_ASAN)
    target_compile_options(${PROJECT_NAME} PRIVATE 
        $<$<CONFIG:Debug>: -fsanitize=address>)
endif()
# target_link_options(${PROJECT_NAME} PRIVATE
#     $<$<CONFIG:Debug>:/NODEFAULTLIB:msvcrt>)

#####################################################
# Release
#####################################################
target_compile_options(${PROJECT_NAME} PRIVATE 
    $<$<CONFIG:Release>: -O2 -MT>)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:NDEBUG _NDEBUG>)
# target_link_options(${PROJECT_NAME} PRIVATE
#     $<$<CONFIG:Release>:/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup /NODEFAULTLIB:libcmt>)
