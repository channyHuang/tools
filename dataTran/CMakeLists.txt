CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
set(target DataTran)

project(${target})

set(CMAKE_PREFIX_PATH 
	"F:/thirdLib/Opencv2.4.9/opencv/build"
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	"F:/thirdLib/boost_1_56_0"
	)
set(Eigen_DIR "F:/thirdLib/eigen_3.3.2")	
include_directories(${Eigen_DIR})	

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

add_executable(${target}
	${HEADERS}
	${SOURCES}
	)
target_link_libraries(${target}
	${OpenCV_LIBS}
	Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	)	