cmake_minimum_required(VERSION 3.13)
project(projeto_aed_2022 C)

set(CMAKE_C_STANDARD 99)
include_directories(libs_src)
add_executable( projeto_aed_2022 main.c projeto.c projeto.h aed1_lp1_2223_proj_part1_chars.h aed1_lp1_2223_proj_part1_ints.h libs_src/lib_util.h libs_src/lib_util.c libs_src/lib_stats.h libs_src/lib_stats.c)