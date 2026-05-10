cmake_minimum_required(VERSION 4.2)
project(GraphsHw1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(GraphsHw1
        graph.cpp
        graph.h
        main.cpp
        tests.cpp
)

configure_file(
        ${CMAKE_SOURCE_DIR}/graph_dijkstra.txt
        ${CMAKE_BINARY_DIR}/graph_dijkstra.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/dag.txt
        ${CMAKE_BINARY_DIR}/dag.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/graph1.txt
        ${CMAKE_BINARY_DIR}/graph1.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/graph1k.txt
        ${CMAKE_BINARY_DIR}/graph1k.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/graph10k.txt
        ${CMAKE_BINARY_DIR}/graph10k.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/graph100k.txt
        ${CMAKE_BINARY_DIR}/graph100k.txt
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/dagtopo.txt
        ${CMAKE_BINARY_DIR}/dagtopo.txt
        COPYONLY
)


configure_file(
        ${CMAKE_SOURCE_DIR}/dagmorepaths.txt
        ${CMAKE_BINARY_DIR}/dagmorepaths.txt
        COPYONLY
)


configure_file(
        ${CMAKE_SOURCE_DIR}/dcg.txt
        ${CMAKE_BINARY_DIR}/dcg.txt
        COPYONLY
)