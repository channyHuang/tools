cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	)

project(tip)
	
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

file (GLOB HEADERS "*.h" "*.hpp")
file (GLOB SOURCES "[^_]*.cpp")
file (GLOB UIS "*.ui")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
	
QT5_WRAP_CPP (MISTUDIO_HEADERS_MOC ${HEADERS})	
QT5_WRAP_UI (qt_files 
	${UIS}
	)	
QT5_ADD_RESOURCES(MISTUDIO_QRC_RCC tip.qrc)	
	
add_executable(tip
	${SOURCES}
	${MISTUDIO_HEADERS_MOC}
	${MISTUDIO_QRC_RCC}	
	${qt_files}
	)

TARGET_LINK_LIBRARIES(tip
	Qt5::Widgets
	Qt5::Gui
	Qt5::Core
	)	