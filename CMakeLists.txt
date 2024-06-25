cmake_minimum_required(VERSION 3.28)
project(Frog_typer_project)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(fmt)

FetchContent_MakeAvailable(SFML)

add_executable(Frog_typer_project main.cpp
        Text.cpp
        Text.h
        Timer.cpp
        Timer.h
        Frog.cpp
        Frog.h
        WordManager.cpp
        WordManager.h
        FPS.h
        Menu.cpp
        Menu.h
        GameData.cpp
        GameData.h
        Settings.cpp
        Settings.h
)
target_link_libraries(Frog_typer_project sfml-graphics)
target_link_libraries(Frog_typer_project fmt)
