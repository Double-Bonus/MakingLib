# Simple application for including library and using unit tests

Requirements:
- Cmake
- Make (if not using Visual Studio)

## Building project
Simplest way is to use VisualStudio with Linux c++ developemt tools
 1. Clone project
 2. In project directory press "Open with Visual Sudio"
 3. Cmake will compile automaticlly
 4. Select "Set as startup item" main.c - if you want to run program, testRunner.cpp - to run unit tests 


# Functionallity
Project loads and prints to console data from a txt file about university study programs. You have to enter your total grades % to find which universities could accept you.

Program can be run with two optional flags: `mas` - to load masters data  instead of bachelors. `lit` - to not show universities in Lithuania.
