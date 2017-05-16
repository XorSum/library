cmake_minimum_required(VERSION 3.7)
project(library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CBook.cpp CBook.h CUser.cpp CUser.h CReader.cpp CReader.h CReaderManager.cpp CReaderManager.h CBookManager.cpp CBookManager.h)
add_executable(library ${SOURCE_FILES})