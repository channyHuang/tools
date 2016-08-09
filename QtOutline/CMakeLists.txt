cmake_minimum_required(VERSION 3.0)
set(target QtOutline)
set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
)

set(GL_DIR "E:/thirdLib/gl")

project(${target})

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

QT5_WRAP_CPP(MISTUDIO_HEADERS_MOC ${HEADERS})
QT5_WRAP_UI(qt_files ${UIS})
QT5_ADD_RESOURCES(MISTUDIO_QRC_RCC ${QRCS})

add_executable(${target}
	${SOURCES}
	${MISTUDIO_HEADERS_MOC}
	${MISTUDIO_QRC_RCC}	
	${qt_files}
)

target_link_libraries(${target}
	Qt5::Gui
	Qt5::Widgets
	Qt5::Core
	Qt5::OpenGL
	glu32
	opengl32
)