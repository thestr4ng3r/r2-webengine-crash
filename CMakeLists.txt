
cmake_minimum_required(VERSION 3.2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui WebEngineWidgets)

find_package(Radare2 REQUIRED)
include_directories(${RADARE2_INCLUDE_DIRS})
link_directories(${RADARE2_LIBRARY_DIRS})

add_executable(r2webengine
		main.cpp)

target_link_libraries(r2webengine Qt5::Core Qt5::Widgets Qt5::Network Qt5::WebEngineWidgets)
target_link_libraries(r2webengine ${RADARE2_LIBRARIES})