cmake_minimum_required(VERSION 3.20.2)

# Set the project name
project(AOLibrary VERSION 1.0 LANGUAGES CXX)

if (NOT MSVC)
	message(fatal_error "Debes usar el compilador de Visual Studio")
endif()

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Prevent CMake to append `lib` to the output filename
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Set compiler flags
add_compile_options(-W4)

# Get a list of all *.cpp and files to pass to the compiler
file(GLOB_RECURSE SOURCE_CODE CONFIGURE_DEPENDS "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCE_CODE})

# Include header files from `include` directory
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Include from `lib` directory
file(GLOB STATIC_LIBS "${CMAKE_SOURCE_DIR}/lib/*.lib")
target_link_libraries(${PROJECT_NAME} PRIVATE ${STATIC_LIBS})