cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME SCVCG)
project(${PROJECT_NAME})

set(PUBLIC_INCLUDES
	include/SCVCG.h
)

set(PRIVATE_SOURCES
	src/SCVCG.c
)

set(ALL_SOURCES
	${PUBLIC_INCLUDES}
	${PRIVATE_SOURCES}
)

add_library(${PROJECT_NAME} STATIC
	${ALL_SOURCES}
)

add_library(${PROJECT_NAME}_SHARED SHARED
	${ALL_SOURCES}
)

add_library(${PROJECT_NAME}_MODULE MODULE
	${ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)


target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)