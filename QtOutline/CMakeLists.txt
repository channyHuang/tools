cmake_minimum_required(VERSION 3.0)
set(target QtOutline)
set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.7.0/5.7/msvc2013"
)

set(GL_DIR "D:/useAsE/thirdLib/gl")

project(${target})
set(CMAKE_AUTOMOC ON)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5OpenGL REQUIRED)


file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
file(GLOB UIS "*.ui")
file(GLOB QRCS "*.qrc")

include_directories(${target}
	${GL_DIR}	
)

link_directories(${target}
	${GL_DIR}
)

add_executable(${target}
	${SOURCES}
	${HEADERS}
)

target_link_libraries(${target}
	Qt5::Gui
	Qt5::Widgets
	Qt5::Core
	Qt5::OpenGL
	freeglut_staticd
)