cmake_minimum_required(VERSION 2.8)

project ( Server CXX )
file ( GLOB_RECURSE SRC *.?pp )

add_subdirectory(Message)
add_library(Server SHARED ${SRC})
target_link_libraries(Server Qt5::Core)
target_link_libraries(Server Qt5::Gui)
target_link_libraries(Server Utility)
target_link_libraries(Server Networking)
target_link_libraries(Server TcpNetworking)
target_link_libraries(Server AssetInterfaces)
target_link_libraries(Server AssetGenerics)
target_link_libraries(Server Assets)
target_link_libraries(Server Wavefront)
target_link_libraries(Server QImageLoader)
target_link_libraries(Server Message)
