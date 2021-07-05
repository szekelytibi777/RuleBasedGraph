cmake_minimum_required(VERSION 3.16)

# set the project name
project(AIMOTIVE)

option(BUILD_GRAPHVIZ "Enable a small and simple C++ library to produce .gv files for GraphViz" ON)

if(BUILD_GRAPHVIZ)
     message(STATUS "Building Graphviz")
     add_subdirectory(gvpp)
     add_compile_definitions("GRAPHVIZ_RENDERER")
     set(GVPP_LIB "gvpp")
endif()

set(PROJECT_ICLUDE_DIR "Graph")

list(APPEND CXX_FLAGS "-std=c++17") 

include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/gvpp/src)

file(GLOB GRAPH_SRC
     "Graph/*.cpp"
     "Graph/Rules/*.cpp"
)
add_library(graph STATIC ${GRAPH_SRC})
link_directories("gvpp/lib")
add_executable(main main.cpp  ${GRAPH_SRC})  
target_link_libraries( main graph ${GVPP_LIB})
#add_executable(test test.cpp)
#target_link_libraries( test graph ${GVPP_LIB})


