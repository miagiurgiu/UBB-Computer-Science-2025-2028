cmake_minimum_required(VERSION 4.2)
project(MedicalAnalysisRedoneTest2OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(MedicalAnalysisRedoneTest2OOP
        domain/analysis.cpp
        domain/analysis.h
        domain/bmi.cpp
        domain/bmi.h
        domain/bp.cpp
        domain/bp.h
        repo/person.cpp
        repo/person.h
        ui/ui.cpp
        ui/ui.h
        main.cpp)
