cmake_minimum_required(VERSION 3.2)

project(deduction)

# # # _ _ _ _ _ _ _ _ P R O J E C T _ L I B _ _ _ _ _ _ _ # # #
add_executable(deduction
    inc/template_functions.h
    src/main.cpp
)

target_include_directories(deduction
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

# # # _ _ _ _ _ _ _ _ _ _ P R O J E C T _ _ _ _ _ _ _ _ _ _ # # #
# add_executable(helloworld_cli
#     main.cpp
# )

# set_target_properties(helloworld_cli helloworld PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED ON
# )

# target_link_libraries(helloworld_cli
#     PRIVATE
#         helloworld
# )

# # # _ _ _ _ _ _ _ _ _ _ _ T E S T S _ _ _ _ _ _ _ _ _ _ _ # # #
#  if(WITH_GOOGLE_TEST)
#     add_executable(deductions
#         tests/main.cpp
#         tests/deductions.cpp
#     )

#     set_target_properties(deductions
#         PROPERTIES
#         CXX_STANDARD 17
#         CXX_STANDARD_REQUIRED ON
#     )

#     target_include_directories(deductions
#         PRIVATE
#             ${gtest_SOURCE_DIR}/include
#     )

#     target_link_libraries(deductions
#         PRIVATE
#             GTest::gtest
#             GTest::gtest_main
#             deduction
#     )
# endif()

# if (MSVC)
#     target_compile_options(helloworld
#         PRIVATE
#             /W4
#     )

#     target_compile_options(helloworld_cli
#         PRIVATE
#             /W4
#     )

#     if(WITH_GOOGLE_TEST)
#         target_compile_options(test_version
#             PRIVATE
#                 /W4
#         )
#     endif()
# else ()
#     target_compile_options(helloworld
#         PRIVATE
#             -Wall -Wextra -pedantic -Werror
#     )

#     target_compile_options(helloworld_cli
#         PRIVATE
#             -Wall -Wextra -pedantic -Werror
#     )

#     if(WITH_GOOGLE_TEST)
#         target_compile_options(test_version
#             PRIVATE
#                 -Wall -Wextra -pedantic -Werror
#         )
#     endif()
# endif()

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
