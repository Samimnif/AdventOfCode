cmake_minimum_required(VERSION 3.30)
project(AdventOfCode C)

set(CMAKE_C_STANDARD 11)

add_executable(AdventOfCode main.c
        Day1/Day1_part1.c
        Day1/Day1_part2.c
        Day2/Day2_part1.c
        Day11/Day11_part1.c)
