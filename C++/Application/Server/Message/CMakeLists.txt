cmake_minimum_required(VERSION 2.8)

project ( Message CXX )
file ( GLOB_RECURSE SRC *.?pp )
add_library(Message SHARED ${SRC})

target_link_libraries(Message Qt5::Core)
target_link_libraries(Message Qt5::Gui)
target_link_libraries(Message Utility)
