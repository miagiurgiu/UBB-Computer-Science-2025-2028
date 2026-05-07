cmake_minimum_required(VERSION 4.2)
project(BuildYourCarOOPTest2)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(BuildYourCarOOPTest2
        domain/engine.cpp
        domain/engine.h
        domain/electric.cpp
        domain/electric.h
        domain/turbo.cpp
        domain/turbo.h
        domain/car.cpp
        domain/car.h
        service/service.cpp
        service/service.h
        ui/ui.cpp
        ui/ui.h
        main.cpp)
