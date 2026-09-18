cmake_minimum_required(VERSION 4.3)
project(Palword_wish)
include(FetchContent)
set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)
add_executable(Palword_wish src/main.cpp
        src/moacreature.cpp
        inc/moacreature.h
        src/Collections_Moacreature.cpp
        inc/Collections_Moacreature.h
        src/MoaDex.cpp
        inc/MoaDex.h
        src/mon_MoaDex.cpp
        inc/mon_MoaDex.h
        Ressources/Ressources.h
        src/GUI.cpp
        inc/GUI.h)
target_link_libraries(Palword_wish
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)