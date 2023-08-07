# CMakeList.txt: Computing_Geometry 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Computing_Geometry")

include_directories(Core/Base)
include_directories(Core/Primitive)
include_directories(Core)

# 将源代码添加到此项目的可执行文件。
add_executable (Computing_Geometry "Computing_Geometry.cpp" "Computing_Geometry.h")
add_executable (Demo "Sample/Demo.cpp" )
add_executable (Thread_1 "Thread/Thread_1.cpp" "Thread/ThreadDemo/2_launch_a_thread.h")
add_executable (Thread_2 "Thread/Thread_2_joinable.cpp" )
add_executable (Thread_Demo "Thread/Thread_Demo.cpp" )
add_executable (Thread_SubThread "Thread/Thread_SubThread.cpp" )
add_executable (CG_EarClipping "ComputeGeometryDemo/EarClipping.cpp" "ComputeGeometryDemo/Trangulation.cpp" "ComputeGeometryDemo/Triangulation.h")

# TODO: 如有需要，请添加测试并安装目标。
