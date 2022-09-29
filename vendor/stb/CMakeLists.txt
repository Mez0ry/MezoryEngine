cmake_minimum_required(VERSION 3.9)
project(Stb)

add_library(stb STATIC include/stb_image.h src/stb.c)
target_include_directories(stb PUBLIC include/)