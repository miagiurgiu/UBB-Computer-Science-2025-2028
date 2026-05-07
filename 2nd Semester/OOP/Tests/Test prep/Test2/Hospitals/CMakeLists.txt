cmake_minimum_required(VERSION 4.2)
project(Hospital)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(Hospital
        domain/department.cpp
        domain/department.h
        domain/neonatal.cpp
        domain/neonatal.h
        domain/surgery.cpp
        domain/surgery.h
        repo/abstract_repo.cpp
        repo/abstract_repo.h
        repo/file_repo.cpp
        repo/file_repo.h
        service/service.cpp
        service/service.h
        ui/ui.cpp
        ui/ui.h
        start/main.cpp)
