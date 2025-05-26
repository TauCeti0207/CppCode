cmake_minimum_required(VERSION 3.28.0)
project(CppCode)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置默认构建类型为 Debug（包含调试信息）
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# 为 Debug 构建添加调试标志
set(CMAKE_C_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0  -g")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0  -g")

# 添加子目录
add_subdirectory(01CPP入门)
add_subdirectory(02类与对象)
add_subdirectory(03内存管理)
add_subdirectory(04模板)
add_subdirectory(05string)
add_subdirectory(06vector)
add_subdirectory(07list)
add_subdirectory(08stack&queue)