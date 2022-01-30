#include "ip_filter.h"

#include <algorithm>
#include <iostream>
#include <tuple>

IpPool read_ip_pool()
{
    IpPool pool;
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split_string(line, '\t');
        pool.push_back(split_string(v.at(0), '.'));
    }
    return pool;
}

std::vector<std::string> split_string(const std::string& str, char delim)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop  = str.find_first_of(delim);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop  = str.find_first_of(delim, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_ip_pool(IpPool const& ip_pool)
{
    for(auto const& ip: ip_pool)
    {
        for(auto const& octet: ip)
        {
            if(octet != ip.front())
            {
                std::cout << ".";
            }
            std::cout << octet;
        }
        std::cout << std::endl;
    }
}

void sort_ip_addresses(IpPool& ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), is_ip_greater);
}

bool is_ip_greater(IpAddress const& lhs, IpAddress const& rhs)
{
    auto const ip_left =
        std::make_tuple(stoi(lhs[ 0 ]), stoi(lhs[ 1 ]), stoi(lhs[ 2 ]), stoi(lhs[ 3 ]));

    auto const ip_right =
        std::make_tuple(stoi(rhs[ 0 ]), stoi(rhs[ 1 ]), stoi(rhs[ 2 ]), stoi(rhs[ 3 ]));

    return ip_left > ip_right;
}

IpPool filter_ip_addresses(IpPool const& ip_pool, int octet)
{
    IpPool pool;

    std::copy_if(ip_pool.cbegin(),
                 ip_pool.cend(),
                 std::back_inserter(pool),
                 [ &octet ](IpAddress const& ip)
                 {
                     return ip.front() == std::to_string(octet);
                 });
    return pool;
}

IpPool filter_ip_addresses(IpPool const& ip_pool, int octet1, int octet2)
{
    IpPool pool;

    std::copy_if(ip_pool.cbegin(),
                 ip_pool.cend(),
                 std::back_inserter(pool),
                 [ &octet1, &octet2 ](IpAddress const& ip)
                 {
                     return ip[ 0 ] == std::to_string(octet1) ||
                            ip[ 1 ] == std::to_string(octet2);
                 });
    return pool;
}

IpPool filter_any_octet(IpPool const& ip_pool, int octet)
{
    IpPool pool;

    std::copy_if(ip_pool.cbegin(),
                 ip_pool.cend(),
                 std::back_inserter(pool),
                 [ &octet ](IpAddress const& ip)
                 {
                     return std::any_of(ip.cbegin(),
                                        ip.cend(),
                                        [ &octet ](std::string const& oct)
                                        {
                                            return std::atoi(oct.c_str()) == octet;
                                        });
                 });
    return pool;
}
