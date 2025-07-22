cmake_minimum_required(VERSION 3.28)
project(Test_Proj LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# Fetch SFML
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

#Add Executables in here 
add_executable(main 
    src/main.cpp
    src/Game.cpp
    src/StateMan.cpp
    src/AssetMan.cpp
    src/MainMenu.cpp
    src/GamePlay.cpp
    src/Snake.cpp
    src/GameOver.cpp
    src/PauseGame.cpp
    # add other .cpp files as needed
)
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)

# INclude my libraries 
target_include_directories(main PRIVATE include)
