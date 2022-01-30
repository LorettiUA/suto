cmake_minimum_required(VERSION 3.2)

project(ip_filter)

# # # _ _ _ _ _ _ _ _ P R O J E C T _ L I B _ _ _ _ _ _ _ # # #
set(PROJECT_LIB_NAME ${PROJECT_NAME}_lib)

add_library(${PROJECT_LIB_NAME}
    inc/ip_filter.h
    src/ip_filter.cpp
)

target_include_directories(${PROJECT_LIB_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
    PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}"
)

# # # _ _ _ _ _ _ _ _ _ _ P R O J E C T _ _ _ _ _ _ _ _ _ _ # # #
add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_LIB_NAME}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# # # _ _ _ _ _ _ _ _ _ _ _ T E S T S _ _ _ _ _ _ _ _ _ _ _ # # #
 if(WITH_GOOGLE_TEST)
    set(PROJECT_TESTS_NAME ${PROJECT_NAME}_tests)
    add_executable(${PROJECT_TESTS_NAME}
        tests/main.cpp
        tests/ip_pool.h
        tests/ip_filter_tests.cpp
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
            ${PROJECT_LIB_NAME}
    )
endif()

if (MSVC)
    target_compile_options(${PROJECT_LIB_NAME}
        PRIVATE
            /W4
    )

    target_compile_options(${PROJECT_NAME}
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
    target_compile_options(${PROJECT_LIB_NAME}
        PRIVATE
            -Wall -Wextra -pedantic -Werror
    )

    target_compile_options(${PROJECT_NAME}
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

# install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)
# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
# set(CPACK_PACKAGE_CONTACT example@example.com)
# include(CPack)

# if(WITH_GOOGLE_TEST)
#     add_test(test_version test_version)
# endif()
