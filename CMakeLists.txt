cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME SCVCG)
project(${PROJECT_NAME})

include("${PROJECT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

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

find_package(Opus CONFIG REQUIRED)
# add opus to the list of dependencies

target_link_libraries(${PROJECT_NAME} PRIVATE Opus::opus)
target_link_libraries(${PROJECT_NAME}_SHARED PRIVATE Opus::opus)
target_link_libraries(${PROJECT_NAME}_MODULE PRIVATE Opus::opus)
# connect opus

find_package(portaudio CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE portaudio)
target_link_libraries(${PROJECT_NAME}_SHARED PRIVATE portaudio)
target_link_libraries(${PROJECT_NAME}_MODULE PRIVATE portaudio)

find_package(libSRTP CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE libSRTP::srtp2)
target_link_libraries(${PROJECT_NAME}_SHARED PRIVATE libSRTP::srtp2)
target_link_libraries(${PROJECT_NAME}_MODULE PRIVATE libSRTP::srtp2)