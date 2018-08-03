cmake_minimum_required(VERSION 2.8.9)
project (linkedlist)
add_executable(linkedlist linkedlist.cpp)
set_target_properties(linkedlist PROPERTIES COMPILE_FLAGS "-save-temps -masm=intel -fverbose-asm")
