cmake_minimum_required(VERSION 3.20)
project(The_Adventures_of_the_Unscrupulous_Brother)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
list(REMOVE_ITEM SRC ${PROJECT_SOURCE_DIR}/src/getandmoving.cpp)
list(REMOVE_ITEM SRC ${PROJECT_SOURCE_DIR}/src/trigger.cpp)

set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)

include_directories(${HEADPATH})

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})

find_library(CURSES curses /usr/lib /usr/local/lib NO_DEFAULT_PATH)
link_libraries(curses)
add_executable(
  un-bro
  ${SRC})
