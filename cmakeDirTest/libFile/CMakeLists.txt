cmake_minimum_required(VERSION 3.0.0)

project(libFile)

list(APPEND USER_H
	add.h
)

list(APPEND USER_CPP
	add.cpp
)

add_library(libFile STATIC ${USER_CPP} ${USER_H})