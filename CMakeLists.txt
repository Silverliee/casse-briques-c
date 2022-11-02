cmake_minimum_required(VERSION 3.23)
project(casse_brique_c C)

set(CMAKE_C_STANDARD 99)

SET(PROJECT_HEADERS
        code/prototypes/bomb.h
        code/prototypes/game.h
        code/prototypes/gameEntity.h
        code/prototypes/inventory.h
        code/prototypes/map.h
        code/prototypes/player.h
        code/prototypes/menu.h)
SET(PROJECT_SOURCES
        code/sources/bomb.c
        code/sources/game.c
        code/sources/gameEntity.c
        code/sources/inventory.c
        code/sources/map.c
        code/sources/player.c
        code/sources/menu.c)

add_executable(casse_brique_c ${PROJECT_SOURCES} ${PROJECT_HEADERS} main.c)
