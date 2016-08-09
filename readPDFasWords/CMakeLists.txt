cmake_minimum_required(VERSION 3.0.0)

set(target readPDFasWords)

set(CMAKE_PREFIX_PATH 
	"E:/thirdLib/OpenCV/opencv/build"
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	)
	
project(${target})
find_package(OpenCV REQUIRED)
find_package(Qt5Core REQUIRED)

file (GLOB HEADERS "*.h" "*.hpp")
file (GLOB SOURCES "*.cu" "*.c" "*.cpp")

include_directories(${target}
	${OpenCV_INCLUDE_DIRS}
	)

add_executable(${target}
	${HEADERS}
	${SOURCES}
)	

target_link_libraries(${target}
	${OpenCV_LIBS}
	Qt5::Core
)		