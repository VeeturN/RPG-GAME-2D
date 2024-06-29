cmake_minimum_required(VERSION 3.27)
project(GAME3)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(GAME3 src/main.cpp
        src/Player.cpp
        src/Player.h
        src/Animation.cpp
        src/Animation.h
        src/TitleMap.cpp
        src/TitleMap.h
        src/TileMap.cpp
        src/TileMap.h
        src/Inject.cpp
        src/Inject.h
        src/Skeleton.cpp
        src/Skeleton.h
        src/Ghost.cpp
        src/Ghost.h
        src/Wizard.cpp
        src/Wizard.h
        src/Bot1.cpp
        src/Bot1.h
        src/Bot2.cpp
        src/Bot2.h
        src/Skeleton2.cpp
        src/Skeleton2.h
        src/Skeleton3.cpp
        src/Skeleton3.h
)
target_link_libraries(GAME3 fmt)
target_link_libraries(GAME3 sfml-graphics)