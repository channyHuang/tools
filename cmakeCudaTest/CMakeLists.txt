cmake_minimum_required(VERSION 3.0.0)

project(cmakeCudaTest)

find_package(CUDA REQUIRED)

list(APPEND SRC_H
	kernal.h
	)
	
list(APPEND SRC_CU
	kernel.cu
	main.cpp
)

list(APPEND USER_INC ${CUDA_INCLUDE_DIRS})

# Dont propogate host flags into CUDA environment.
set(CUDA_PROPAGATE_HOST_FLAGS off)

# Generate code for 2.0 and 3.0 CUDA compute architectures (TODO: Verify this works)
set(CUDA_NVCC_FLAGS "-use_fast_math -gencode arch=compute_30,code=sm_30 -gencode arch=compute_20,code=sm_20" )

include_directories( ${USER_INC} )
CUDA_ADD_EXECUTABLE(cmakeCudaTest ${SRC_H} ${SRC_CU} )