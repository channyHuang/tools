cmake_minimum_required(VERSION 3.0.0)

set(target readFixFiles)

set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	)
	
project(${target})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

file (GLOB HEADERS "*.h" "*.hpp")
file (GLOB SOURCES "*.cu" "*.c" "*.cpp")

include_directories(${target}
	
	)

add_executable(${target}
	${HEADERS}
	${SOURCES}
)	

target_link_libraries(${target}
	Qt5::Core
	Qt5::Widgets
	Qt5::Gui
)		