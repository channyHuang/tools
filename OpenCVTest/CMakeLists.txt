CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
project(Point2PointProj)

set(CMAKE_PREFIX_PATH "F:/thirdLib/Opencv2.4.9/opencv/build")

find_package(OpenCV REQUIRED)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_executable(Point2PointProj
	${HEADERS}
	${SOURCES}
	)
target_link_libraries(Point2PointProj
	${OpenCV_LIBS}
	)	