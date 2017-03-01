CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
project(Point2PointProj)

set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.7.0_x64/5.7/msvc2015_64"
	"D:/useAsE/thirdLib/OpenCV3/opencv/build")

find_package(OpenCV REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "pointGrab.cpp")

add_executable(Point2PointProj
	${HEADERS}
	${SOURCES}
	)
target_link_libraries(Point2PointProj
	${OpenCV_LIBS}
	Qt5::Core
	Qt5::Gui
	)	
