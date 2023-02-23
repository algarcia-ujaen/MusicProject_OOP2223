cmake_minimum_required(VERSION 3.24)
project(myMusicProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(myMusicProject.exe main.cpp Song.cpp Song.h MusicException.cpp MusicException.h)
