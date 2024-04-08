cmake_minimum_required (VERSION 2.8) #最低版本为2.8

project (main) #确定项目名称为main

message(STATUS "This is BINARY dir" ${MAIN_BINARY_DIR}) #打印二进制文件保存目录

message(STATUS "This is SOURCE dir" ${MAIN_SOURCE_DIR}) #打印源文件保存路径

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #目标二进制可执行文件的存放位置为bin文件夹

aux_source_directory (H:/work/qiuqien_hw1/src SRC_LIST) #在src中找源文件

include_directories (H:/work/qiuqien_hw1/inc) #增加头文件的搜索路径

add_executable (main ${SRC_LIST}) # 生成依赖于那几个.c文件的main.exe