cmake_minimum_required(VERSION 3.5.1)
project(props)

# Setting CMAKE variables
# C++11 Standard
set(CMAKE_CXX_STANDARD 11)
# G++ glags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DELPP_THREAD_SAFE -DELPP_FORCE_USE_STD_THREAD -DELPP_STACKTRACE_ON_CRASH -DELPP_NO_DEFAULT_LOG_FILE") 
add_compile_options(-pthread)

# Include dirs
include_directories("include/utils")

# Source files
file(GLOB_RECURSE SOURCES "src/*.cc")

# Executable
add_executable(props ${SOURCES})

# Linking
target_link_libraries(props ${PROJECT_LINK_LIBS})
