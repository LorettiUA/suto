cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "3" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

# # # _ _ _ _ _ _ _ _ P R O J E C T _ L I B _ _ _ _ _ _ _ # # #
add_library(helloworld
    lib.cpp
)

target_include_directories(helloworld
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

# # # _ _ _ _ _ _ _ _ _ _ P R O J E C T _ _ _ _ _ _ _ _ _ _ # # #
add_executable(helloworld_cli
    main.cpp
)

set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(helloworld_cli
    PRIVATE
        helloworld
)

# # # _ _ _ _ _ _ _ _ _ _ _ T E S T S _ _ _ _ _ _ _ _ _ _ _ # # #
 if(WITH_GOOGLE_TEST)
    add_executable(test_version
        tests/main.cpp
        tests/test_version.cpp
    )

    set_target_properties(test_version
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    target_include_directories(test_version
        PRIVATE
            ${gtest_SOURCE_DIR}/include
    )

    target_link_libraries(test_version
        PRIVATE
            GTest::gtest
            GTest::gtest_main
            helloworld
    )
endif()

if (MSVC)
    target_compile_options(helloworld
        PRIVATE
            /W4
    )

    target_compile_options(helloworld_cli
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
    target_compile_options(helloworld
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

    target_compile_options(helloworld_cli
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
