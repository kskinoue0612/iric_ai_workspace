cmake_minimum_required(VERSION 3.15)
project(test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(test
    main.cpp
    worker.cpp
    workerhandler.cpp
)

target_link_libraries(test PRIVATE Threads::Threads)
