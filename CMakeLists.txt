cmake_minimum_required(VERSION 3.24)
project(myMusicProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(myMusicProject.exe main.cpp Song.cpp Song.h MusicException.cpp MusicException.h Artist.cpp Artist.h PlayList.cpp PlayList.h Melody.cpp Melody.h Lyrics.cpp Lyrics.h Singer.cpp Singer.h Player.cpp Player.h CanBeSaved.h)
