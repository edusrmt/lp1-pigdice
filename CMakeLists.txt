cmake_minimum_required(VERSION 3.5)
project (PigDice)

set(GCC_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS} ${PREPROCESSING_FLAGS}")

set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)

set(HEADER_PATH ${PROJECT_SOURCE_DIR}/include)
include_directories(${HEADER_PATH})

set(EXECUTABLE_NAME "PigDice")
set(HEADER_FILES
    ${HEADER_PATH}/dice.h
    ${HEADER_PATH}/pig_dice_game.h
    ${HEADER_PATH}/pig_dice_ia.h
)
set(SOURCE_FILES
    ${SOURCE_PATH}/dice.cpp
    ${SOURCE_PATH}/pig_dice_game.cpp
    ${SOURCE_PATH}/pig_dice_ia.cpp
)

file(GLOB SOURCES "src/*.cpp")
add_executable(${EXECUTABLE_NAME} src/main.cpp ${HEADER_FILES} ${SOURCE_FILES})
target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_11)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)