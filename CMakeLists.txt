cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME SCVCG)
project(${PROJECT_NAME})

set(PUBLIC_INCLUDES
	include/SCVCG.h
)
# external file to connect to lib

set(PRIVATE_SOURCES
	src/SCVCG.c
)
# files for compiling lib

set(ALL_SOURCES
	${PUBLIC_INCLUDES}
	${PRIVATE_SOURCES}
)
# I collect all resources in one variable

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ALL_SOURCES}
)
# I collect all the files for the IDE

add_library(${PROJECT_NAME} STATIC
	${ALL_SOURCES}
)
add_library(${PROJECT_NAME}_SHARED SHARED
	${ALL_SOURCES}
)
add_library(${PROJECT_NAME}_MODULE MODULE
	${ALL_SOURCES}
)
# create a library

target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_include_directories(${PROJECT_NAME} PRIVATE src)
# set paths to headers