cmake_minimum_required(VERSION 4.2)
project(t2_miagiurgiu_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(ui)

add_executable(t2_miagiurgiu_1
        ui/ui.cpp
        ui/ui.h
        main.cpp
        service/service.cpp
        service/service.h
        domain/county.cpp
        domain/county.h
        domain/party.cpp
        domain/party.h
        domain/alliance.cpp
        domain/alliance.h
        domain/independent.cpp
        domain/independent.h)
