cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)
project(showingPly)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	)
set(Eigen_INCLUDEDIR "F:/thirdLib/eigen_3.3.2")	
set(PLY_root "F:/thirdLib/PCL 1.7.2/")
set(PLY_INCLUDEDIR "F:/thirdLib/PCL 1.7.2/include/pcl-1.7/")
set(PLY_LIBRARYDIR "F:/thirdLib/PCL 1.7.2/lib")
set(BOOST_ROOT F:/thirdLib/boost_1_56_0)
set(BOOST_INCLUDEDIR F:/thirdLib/boost_1_56_0)
set(BOOST_LIBRARYDIR F:/thirdLib/boost_1_56_0/lib64-msvc-12.0)	

include_directories(${BOOST_INCLUDEDIR} ${PLY_INCLUDEDIR} ${Eigen_INCLUDEDIR})
link_directories(${BOOST_LIBRARYDIR} ${PLY_LIBRARYDIR})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Qt5Gui REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")
file(GLOB qtfiles "*.ui" "*.qrc")
		
add_executable(showingPly 
	${SOURCES}
	${HEADERS}
#	${qtfiles}
	)
	
qt5_use_modules(showingPly Widgets Gui Core)		
	
target_link_libraries(showingPly
	Qt5::Gui
	Qt5::Core
	Qt5::Widgets
	)	