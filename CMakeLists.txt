cmake_minimum_required(VERSION 3.0)
project(LeitnerBox)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    src/main.cpp
    src/app.cpp
    src/add.cpp
    src/word.cpp
    src/word_in_test.cpp
    src/file.cpp
    src/login.cpp
    src/user.cpp
    src/choose.cpp
    src/test_summery.cpp
    src/real_test.cpp
    hash-library-master/sha256.cpp
    
)
include_directories(include/ json-develop/include/ hash-library-master/)
add_executable(app ${SOURCES})
target_link_libraries(app sfml-window sfml-system sfml-graphics)