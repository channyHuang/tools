system('nvcc -c AddVectors.cu --compiler-options -fPIC');

mex AddVectorsCuda.cpp AddVectors.obj -lcudart -L'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v6.5/lib/x64'

