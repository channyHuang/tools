cmake_minimum_required(VERSION 3.0)

project(Getpoints)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt5 REQUIRED)
find_package(OpenCV REQUIRED)

file(GLOB ALL_SOURCES
	data.*
	getpoints.*
	selectpt.*
	main.cpp
	)

set(MISTUDIO_HEADERS
	getpoints.h
	selectpt.h
	)
set(MISTUDIO_UIS
	getpoints.ui
	selectpt.ui
	)
set(MISTUDIO_QRCS getpoints.qrc)
set(MISTUDIO_SRCS
	${ALL_SOURCES}
	)
	
QT5_WRAP_CPP (MISTUDIO_HEADERS_MOC ${MISTUDIO_HEADERS})
QT5_WRAP_UI (MISTUDIO_UIS_UIC ${MISTUDIO_UIS})
QT5_ADD_RESOURCES (MISTUDIO_QRC_RCC ${MISTUDIO_QRCS})

add_executable(Getpoints
	${ALL_SOURCES}
	${MISTUDIO_HEADERS_MOC}
	${MISTUDIO_UIS_UIC}
	${MISTUDIO_QRC_RCC}
	getpoints.qrc
	)
	
target_link_libraries(Getpoints
	${OpenCV_LIBS}
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	)