cmake_minimum_required(VERSION 3.11.3)
project(OSM_A_star_search)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 17)

# Add the path of the cmake files to the CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Locate project prerequisites
find_package(io2d REQUIRED)
find_package(Cairo REQUIRED)
find_package(GraphicsMagick REQUIRED)

# Set IO2D flags
set(IO2D_WITHOUT_SAMPLES 1)
set(IO2D_WITHOUT_TESTS 1)

# Add the pugixml library subdirectories
add_subdirectory(thirdparty/pugixml)

# Add GoogleTest library externally
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.13.0
)
set(BUILD_GMOCK OFF)
FetchContent_MakeAvailable(googletest)

file(GLOB SRC_FILES src/*.cpp)
file(GLOB SRC_FILES_FOR_TEST test/utest_rp_a_star_search.cpp src/route_planner.cpp src/model.cpp src/route_model.cpp)

# Add project executable
add_executable(OSM_A_star_search ${SRC_FILES})

target_link_libraries(OSM_A_star_search
    PRIVATE io2d::io2d
    PUBLIC pugixml
)

# Add the testing executable
add_executable(test ${SRC_FILES_FOR_TEST})

target_link_libraries(test 
    gtest_main 
    pugixml
)

# Set options for Linux or Microsoft Visual C++
if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    target_link_libraries(OSM_A_star_search PUBLIC pthread)
endif()

if(MSVC)
	target_compile_options(OSM_A_star_search PUBLIC /D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING /wd4459)
endif()
