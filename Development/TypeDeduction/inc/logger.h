#pragma once

#include <iostream>

#define LOG_ITEM(__item) ", " << #__item << ": " << __item

#define LOG_MSG(__msg)   std::cout << __msg << '\n'

#define LOG_MSG_FUNCTION(__msg)                                                          \
    std::cout << "\n"                                                                    \
              << __FILE__ << ": " << __LINE__ << ": " << __FUNCTION__ << ": " << __msg   \
              << '\n'

#define LOG_MSG_FULL(__msg)                                                              \
    std::cout << "\n"                                                                    \
              << __DATE__ << ": " << __TIME__ << ": " << __FILE__ << ": " << __LINE__    \
              << ": " << __FUNCTION__ << ": " << __msg << '\n'
