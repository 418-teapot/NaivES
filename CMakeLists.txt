cmake_minimum_required(VERSION 3.13)
project(NaivES VERSION "0.0.1")

# C++17 standard support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# enable all warnings and treat them as errors
if(MSVC)
  add_compile_options(/W3 /WX)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  add_compile_options(-Wall -Wno-init-list-lifetime -Werror)
else()
  add_compile_options(-Wall -Werror)
endif()

# some definitions
add_compile_definitions(APP_NAME="NaivES")
add_compile_definitions(APP_VERSION="${PROJECT_VERSION}")
add_compile_definitions(APP_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_compile_definitions(APP_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_compile_definitions(APP_VERSION_PATCH=${PROJECT_VERSION_PATCH})

# project include directories
include_directories(src)

# all of C++ source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# executable
add_executable(naives ${SOURCES})
