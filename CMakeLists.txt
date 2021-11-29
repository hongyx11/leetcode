cmake_minimum_required(VERSION 3.10)

set (PROJECT_NAME Leetcode)
PROJECT(${PROJECT_NAME} CXX)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")   
set(CMAKE_CXX_STANDARD 11)

# directly make an error if in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
message(FATAL_ERROR "In-source builds are not allowed.\n")
endif()

include_directories(include)

add_subdirectory(Backtracking)
foreach(src ${BTSRC})
	add_executable(${src} Backtracking/${src}.cpp)
endforeach()


