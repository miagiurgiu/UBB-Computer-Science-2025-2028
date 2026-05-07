cmake_minimum_required(VERSION 4.2)
project(RealEstate2Test2OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(RealEstate2Test2OOP
        domain/dwelling.cpp
        domain/dwelling.h
        main.cpp
        README.md
        domain/client.cpp
        domain/client.h
        domain/normal.cpp
        domain/normal.h
        domain/wealthy.cpp
        domain/wealthy.h
        service/agency.cpp
        service/agency.h
        ui/ui.cpp
        ui/ui.h)
