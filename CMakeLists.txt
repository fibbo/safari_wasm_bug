cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(safari_pow_bug)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(O_FLAG "-O2") # O1 also shows the same behaviour

set(CMAKE_CXX_FLAGS_RELEASE "${O_FLAG} -std=c++11")


set(src_files example)


add_executable(example ${src_files})

set_target_properties(example PROPERTIES SUFFIX ".bc")
target_compile_options(example PRIVATE -fPIC -fexceptions -fsigned-char)

add_custom_command(TARGET example 
  COMMAND emcc
  --bind
  ${O_FLAG} example.bc
  -o ${CMAKE_SOURCE_DIR}/example.js
)