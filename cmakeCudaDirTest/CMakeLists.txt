
CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

project(cmakeCudaDirTest)

find_package(CUDA REQUIRED)

list(APPEND USER_INC 
	${CUDA_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/lib
	)

include_directories(  ${USER_INC} )

list(APPEND SRC_H
	${PROJECT_SOURCE_DIR}/lib/kernel.h
	)

list(APPEND SRC_CU
	${PROJECT_SOURCE_DIR}/lib/kernel.cu
	)


CUDA_ADD_EXECUTABLE(cmakeCudaDirTest 
	main.cpp
	${SRC_H} 
	${SRC_CU}
	)
	
	