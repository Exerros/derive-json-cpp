cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(derivejson VERSION 1.0.0 LANGUAGES CXX)

#-------------------------------------------------------------------------------

option(DERIVEJSON_BUILD_EXAMPLE OFF)
option(DERIVEJSON_BUILD_TESTS   OFF)

#-------------------------------------------------------------------------------

set(DERIVEJSON_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(DERIVEJSON_EXAMPLE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/example")
set(DERIVEJSON_TESTS_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(DERIVEJSON_CMAKE_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

#-------------------------------------------------------------------------------

find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(Boost 1.76 REQUIRED COMPONENTS system)

if(DERIVEJSON_BUILD_TESTS)
    find_package(GTest 1.10 REQUIRED)
endif()

#-------------------------------------------------------------------------------

add_library(${PROJECT_NAME} INTERFACE)
add_library(nlohmann_json::derivejson ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${DERIVEJSON_INCLUDE_DIR}>)

target_link_libraries(${PROJECT_NAME} INTERFACE
    nlohmann_json::nlohmann_json
    Boost::system)

#-------------------------------------------------------------------------------

if(DERIVEJSON_BUILD_EXAMPLE)
    add_executable(example "${DERIVEJSON_EXAMPLE_DIR}/example.cpp")

    set_target_properties(example PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        BUILD_TYPE DEBUG
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/example)

    target_link_libraries(example ${PROJECT_NAME})

endif()

#-------------------------------------------------------------------------------

if(DERIVEJSON_BUILD_TESTS)
    include(CTest)
    enable_testing()

    set(CTEST_SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/tests")
    set(LIBS_TO_LINK ${PROJECT_NAME} gtest pthread)

    include("${DERIVEJSON_CMAKE_DIR}/functions/test_builder.cmake")
    build_tests(${DERIVEJSON_TESTS_DIR} ${LIBS_TO_LINK})
endif()
