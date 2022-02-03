cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

# TODO Figure out about compiling on github
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(suto)

option(WITH_GOOGLE_TEST "Whether to build Google tests" OFF)

 if(WITH_GOOGLE_TEST)
     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
     add_subdirectory(Modules/GTests EXCLUDE_FROM_ALL)
     enable_testing()
 endif()

#add_subdirectory(Development/Hello)
#add_subdirectory(Development/TypeDeduction)
add_subdirectory(Development/IpFilter)
