cmake_minimum_required(VERSION 4.2)
project(practicalexam_retake_miagiurgiu)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
add_executable(practicalexam_retake_miagiurgiu
        main.cpp
        repo/Repository.cpp
        repo/Repository.h
        service/Service.cpp
        service/Service.h
        gui/gui.cpp
        gui/gui.h
        gui/gui.ui
        domain/Chef.cpp
        domain/Chef.h
        domain/Recipe.cpp
        domain/Recipe.h
        domain/Observer.cpp
        domain/Observer.h
        domain/Subject.cpp
        domain/Subject.h
        gui/all.cpp
        gui/all.h
        gui/all.ui)
target_link_libraries(practicalexam_retake_miagiurgiu Qt6::Widgets)
target_include_directories(practicalexam_retake_miagiurgiu PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/practicalexam_retake_miagiurgiu_autogen/include
)