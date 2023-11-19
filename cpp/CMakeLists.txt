cmake_minimum_required(VERSION 3.9)

project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)

# include(External_GTest.cmake)
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



set(GILDED_ROSE_SOURCE_FILES
    GildedRose.cc
    GildedRose.h
    GildedRoseUnitTests.cc)

set(GILDED_ROSE_TEXT_TESTS_SOURCE_FILES
    GildedRose.cc
    GildedRose.h
    GildedRoseTextTests.cc)

set(SOURCE_FILES
    ${GILDED_ROSE_SOURCE_FILES}
    ${GILDED_ROSE_TEXT_TESTS_SOURCE_FILES})


add_executable(GildedRose ${GILDED_ROSE_SOURCE_FILES})
target_link_libraries(GildedRose gtest_main)

add_executable(GildedRoseTextTests ${GILDED_ROSE_TEXT_TESTS_SOURCE_FILES})
target_link_libraries(GildedRoseTextTests gtest_main)
