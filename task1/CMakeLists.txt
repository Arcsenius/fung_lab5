cmake_minimum_required(VERSION 3.29)
project(fund_alg_lab_5_task1 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(ROOT_DIR "${PROJECT_SOURCE_DIR}")

FILE(GLOB sources "${SRC_DIR}/*.cpp" "${ROOT_DIR}/*.cpp")
FILE(GLOB headers "${INCLUDE_DIR}/*.hpp" "${ROOT_DIR}/*.hpp")

message("Found source files: ${sources}")
message("Found header files: ${headers}")

if(NOT sources)
    message(FATAL_ERROR "No source files found in ${SRC_DIR} or ${ROOT_DIR}")
endif()

add_executable(${PROJECT_NAME} ${sources})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} ${ROOT_DIR})
