cmake_minimum_required(VERSION 4.3)
project(Palword_wish)
include(FetchContent)
set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)
add_executable(Palword_wish src/main.cpp
        src/moacreature.cpp
        inc/moacreature.h
        inc/Collections_Moacreature.cpp
        inc/Collections_Moacreature.h)
target_link_libraries(Palword_wish
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)