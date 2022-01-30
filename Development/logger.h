/**
 * @Author is Oleksandr Gershkul
 * Created on March, 2019
 */

#pragma once

#include <iterator>
#include <iostream>
#include <vector>

#define LOG_MSG(__msg)                    \
        std::cout << __msg << '\n';

#define LOG_MSG_FUNCTION(__msg)                    \
        std::cout << "\n"         \
        << __FILE__ << ": "       \
        << __LINE__ << ": "       \
        << __FUNCTION__ << ": "   \
        << __msg                  \
        << '\n'

#define LOG_MSG_FULL(__msg)       \
        std::cout << "\n"         \
        << __DATE__ << ": "       \
        << __TIME__ << ": "       \
        << __FILE__ << ": "       \
        << __LINE__ << ": "       \
        << __FUNCTION__ << ": "   \
        << __msg                  \
        << '\n'

#define LOG_ITEM(__value)  ", " << #__value << ": " << __value

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << "vector:[";
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
