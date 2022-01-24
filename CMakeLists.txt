cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "3" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(WITH_GOOGLE_TEST "Whether to build Google tests" ON)

configure_file(Development/version.h.in version.h)

add_executable(helloworld_cli Development/main.cpp)
add_library(helloworld
    Development/lib.h
    Development/lib.cpp)

set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(helloworld
    PRIVATE
        "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld_cli
    PRIVATE
        helloworld
)

if(WITH_GOOGLE_TEST)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(Modules/GTests EXCLUDE_FROM_ALL)
    enable_testing()
    add_executable(test_version
        Development/tests/main.cpp
        Development/tests/test_version.cpp)

    set_target_properties(test_version
        PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )

    target_include_directories(test_version
        PRIVATE
            ${gtest_SOURCE_DIR}/include
            Development
    )

    target_link_libraries(test_version
        PRIVATE
            GTest::gtest
            GTest::gtest_main
            helloworld
    )
endif()

if (MSVC)
    target_compile_options(helloworld_cli
        PRIVATE
            /W4
    )

    target_compile_options(helloworld
        PRIVATE
            /W4
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version
            PRIVATE
                /W4
        )
    endif()
else ()
    target_compile_options(helloworld_cli
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_version
            PRIVATE
                -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GOOGLE_TEST)
    add_test(test_version test_version)
endif()
