#include "template_functions.h"

#include "logger.h"
#include "pretty.h"

int i {42};
int const ci {i};
int& ri {i};
int const& rci {i};

void call_function_T()
{
    LOG_MSG("Printing out type deduction of function_T(T param)");
    LOG_MSG("Argument type (i) = " << type_id_with_cvr<decltype(i)>().pretty_name());
    function_T(i);

    LOG_MSG("Argument type (ci) = " << type_id_with_cvr<decltype(ci)>().pretty_name());
    function_T(ci);

    LOG_MSG("Argument type (ri) = " << type_id_with_cvr<decltype(ri)>().pretty_name());
    function_T(ri);

    LOG_MSG("Argument type (rci) = " << type_id_with_cvr<decltype(rci)>().pretty_name());
    function_T(rci);
}

void call_function_CT()
{
    LOG_MSG("Printing out type deduction of function_CT(T const param)");
    LOG_MSG("Argument type (i) = " << type_id_with_cvr<decltype(i)>().pretty_name());
    function_CT(i);

    LOG_MSG("Argument type (ci) = " << type_id_with_cvr<decltype(ci)>().pretty_name());
    function_CT(ci);

    LOG_MSG("Argument type (ri) = " << type_id_with_cvr<decltype(ri)>().pretty_name());
    function_CT(ri);

    LOG_MSG("Argument type (rci) = " << type_id_with_cvr<decltype(rci)>().pretty_name());
    function_CT(rci);
}

void call_function_RT()
{
    LOG_MSG("Printing out type deduction of function_RT(T& param)");
    LOG_MSG("Argument type (i) = " << type_id_with_cvr<decltype(i)>().pretty_name());
    function_RT(i);

    LOG_MSG("Argument type (ci) = " << type_id_with_cvr<decltype(ci)>().pretty_name());
    function_RT(ci);

    LOG_MSG("Argument type (ri) = " << type_id_with_cvr<decltype(ri)>().pretty_name());
    function_RT(ri);

    LOG_MSG("Argument type (rci) = " << type_id_with_cvr<decltype(rci)>().pretty_name());
    function_RT(rci);
}

void call_function_RCT()
{
    LOG_MSG("Printing out type deduction of function_RCT(T const& param)");
    LOG_MSG("Argument type (i) = " << type_id_with_cvr<decltype(i)>().pretty_name());
    function_RCT(i);

    LOG_MSG("Argument type (ci) = " << type_id_with_cvr<decltype(ci)>().pretty_name());
    function_RCT(ci);

    LOG_MSG("Argument type (ri) = " << type_id_with_cvr<decltype(ri)>().pretty_name());
    function_RCT(ri);

    LOG_MSG("Argument type (rci) = " << type_id_with_cvr<decltype(rci)>().pretty_name());
    function_RCT(rci);
}

int main(int argc, char* argv[])
{
    call_function_T();
    call_function_CT();
    call_function_RT();
    call_function_RCT();

    return 0;
}
