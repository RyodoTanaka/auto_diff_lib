cmake_minimum_required(VERSION 2.8)
project(Auto_Diff)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# for include directory
include_directories(
  include
)

# For Boost
find_package(Boost COMPONENTS system REQUIRED)

# For Eigen

# Compile file
set(SRC
  buttom_up_example
  )

foreach(src ${SRC})
  add_executable(${src}
    src/${src}.cpp
    )
  
  target_link_libraries(${src}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    )
  
endforeach(src)
