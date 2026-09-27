cmake_minimum_required(VERSION 3.7.2)
project(Palword_wish)
include(FetchContent)
set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)
add_executable(Palword_wish Creature/src/main.cpp
        Creature/src/moacreature.cpp
        Creature/inc/moacreature.h
        Creature/src/Collections_Moacreature.cpp
        Creature/inc/Collections_Moacreature.h
        Creature/src/MoaDex.cpp
        Creature/inc/MoaDex.h
        Creature/src/mon_MoaDex.cpp
        Creature/inc/mon_MoaDex.h
        Ressources/Ressources.h
        Render/Src/GUI.cpp
        Render/Inc/GUI.h
        Creature/src/main.cpp
        Engine/Inc/GameState.h
        Engine/Src/GameEngine.cpp
        Engine/Inc/GameEngine.h
        Engine/Src/Welcome.cpp
        Engine/Inc/Welcome.h)

target_link_libraries(Palword_wish
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)