#pragma once

#include "logger.h"
#include "pretty.h"

#include <boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

template<typename T>
void function_T(T param)
{
    LOG_MSG(__PRETTY_FUNCTION__);
    LOG_MSG("T = " << type_id_with_cvr<T>().pretty_name());
    LOG_MSG("Param = " << type_id_with_cvr<decltype(param)>().pretty_name());
    LOG_MSG("");
}

template<typename T>
void function_CT(T const param)
{
    LOG_MSG(__PRETTY_FUNCTION__);
    LOG_MSG("T = " << type_id_with_cvr<T>().pretty_name());
    LOG_MSG("Param = " << type_id_with_cvr<decltype(param)>().pretty_name());
    LOG_MSG("");
}

template<typename T>
void function_RT(T& param)
{
    LOG_MSG(__PRETTY_FUNCTION__);
    LOG_MSG("T = " << type_id_with_cvr<T>().pretty_name());
    LOG_MSG("Param = " << type_id_with_cvr<decltype(param)>().pretty_name());
    LOG_MSG("");
}

template<typename T>
void function_RCT(T const& param)
{
    LOG_MSG(__PRETTY_FUNCTION__);
    LOG_MSG("T = " << type_id_with_cvr<T>().pretty_name());
    LOG_MSG("Param = " << type_id_with_cvr<decltype(param)>().pretty_name());
    LOG_MSG("");
}
