cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)

#add_compile_options(-Wwx-config -W)

project(wxWid)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)

add_executable(ui ${project_SRCS})
target_link_libraries(ui ${wxWidgets_LIBRARIES})
target_include_directories(ui PRIVATE ${wxWidgets_INCLUDE_DIRS})

