CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

set(target FactorGraph)

project(${target})

set(CMAKE_PREFIX_PATH 
	"F:/thirdLib/boost_1_56_0"
	"F:/thirdLib/Opencv2.4.9/opencv/build")
#find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)

set(Gtsam_DIR "F:/thirdLib/gtsam-3.2.0/")
include_directories(
	${Gtsam_DIR}
	${Boost_INCLUDE_DIRS}
	)
link_directories(
	${Gtsam_DIR}/build/lib/Debug
	${Boost_LIBRARY_DIRS}
	)

file (GLOB HEADERS "*.h")
file (GLOB SOURCES "*.cpp")

set(LINKFILE 
	CppUnitLiteDebug.lib
	Geographic_d.lib
	gtsamDebug.lib
	wrap_libDebug.lib
	)

add_executable(${target}
	${HEADERS}
	${SOURCES}
)

target_link_libraries(${target}
#	${OpenCV_LIBS}
	${LINKFILE}
)