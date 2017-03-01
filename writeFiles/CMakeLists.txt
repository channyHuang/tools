cmake_minimum_required(VERSION 3.0)

set(CMAKE_PREFIX_PATH
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	)

set(target writeFiles)

project(${target})


find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)


file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")

add_executable(${target}
	${HEADERS}
	${SOURCES}
	)

target_link_libraries(${target}
	Qt5::Gui
	Qt5::Widgets
	Qt5::Core
	)
