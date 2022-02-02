cmake_minimum_required(VERSION 3.2)

#set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
#set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(version VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)

# # # _ _ _ _ _ _ _ _ P R O J E C T _ L I B _ _ _ _ _ _ _ # # #
add_library(version
    lib.h
    lib.cpp
)

target_include_directories(version
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

# # # _ _ _ _ _ _ _ _ _ _ P R O J E C T _ _ _ _ _ _ _ _ _ _ # # #
add_executable(version_cli
    main.cpp
)

set_target_properties(version_cli version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(version_cli
    PRIVATE
        version
)

# # # _ _ _ _ _ _ _ _ _ _ _ T E S T S _ _ _ _ _ _ _ _ _ _ _ # # #
 if(WITH_GOOGLE_TEST)
    set(PROJECT_TESTS_NAME ${PROJECT_NAME}_tests)
    add_executable(${PROJECT_TESTS_NAME}
        tests/main.cpp
        tests/test_version.cpp
    )

    set_target_properties(${PROJECT_TESTS_NAME}
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    target_include_directories(${PROJECT_TESTS_NAME}
        PRIVATE
            ${gtest_SOURCE_DIR}/include
    )

    target_link_libraries(${PROJECT_TESTS_NAME}
        PRIVATE
            GTest::gtest
            GTest::gtest_main
            version
    )
endif()

if (MSVC)
    target_compile_options(version
        PRIVATE
            /W4
    )

    target_compile_options(version_cli
        PRIVATE
            /W4
    )

    if(WITH_GOOGLE_TEST)
        target_compile_options(${PROJECT_TESTS_NAME}
            PRIVATE
                /W4
        )
    endif()
else ()
    target_compile_options(version
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

    target_compile_options(version_cli
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

    if(WITH_GOOGLE_TEST)
        target_compile_options(${PROJECT_TESTS_NAME}
            PRIVATE
                -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS version_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GOOGLE_TEST)
    add_test(${PROJECT_TESTS_NAME} ${PROJECT_TESTS_NAME})
endif()
