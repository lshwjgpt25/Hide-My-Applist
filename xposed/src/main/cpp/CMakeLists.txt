cmake_minimum_required(VERSION 3.6)
project(hma_native)

add_library(hma_native SHARED mkdir_hook.cpp)

find_library(log-lib log)

# nativehook provides a cmake config for prefab
find_package(nativehook REQUIRED CONFIG)

target_link_libraries(hma_native
    nativehook
    ${log-lib}
)
