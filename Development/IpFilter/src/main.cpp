#include "ip_filter.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include <cassert>

int main(int argc, char const* argv[])
{
    try
    {
        IpPool ip_pool = read_ip_pool();

        // Read from cin and print out
        sort_ip_addresses(ip_pool);
        print_ip_pool(ip_pool);

        // Find all 1.*.*.* and print out
        auto const pool_1xxx = filter_ip_addresses(ip_pool, 1);
        print_ip_pool(pool_1xxx);

        // Find all 46.70.*.* and print out
        auto const pool_46_70_xx = filter_ip_addresses(ip_pool, 46, 70);
        print_ip_pool(pool_46_70_xx);

        // Find and octet "46" and print out
        auto const pool_any_46 = filter_any_octet(ip_pool, 46);
        print_ip_pool(pool_any_46);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
