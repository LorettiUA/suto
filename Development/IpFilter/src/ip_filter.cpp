#include "ip_filter.h"

#include <algorithm>
#include <iostream>
#include <tuple>

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

IpPool read_ip_pool()
{
    IpPool pool;
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split_string(line, '\t');
        auto const octets          = split_string(v.at(0), '.');
        pool.push_back(IpAddress {
            stoi(octets[ 0 ]), stoi(octets[ 1 ]), stoi(octets[ 2 ]), stoi(octets[ 3 ])});
    }
    return pool;
}

void print_ip_pool(IpPool const& ip_pool)
{
    for(auto const& ip: ip_pool)
    {
        std::cout << ip[ 0 ] << '.' << ip[ 1 ] << '.' << ip[ 2 ] << '.' << ip[ 3 ]
                  << std::endl;
    }
}

void sort_ip_addresses(IpPool& ip_pool)
{
    std::sort(ip_pool.begin(), ip_pool.end(), is_ip_greater);
}

bool is_ip_greater(IpAddress const& lhs, IpAddress const& rhs)
{
    auto const ip_left  = std::make_tuple(lhs[ 0 ], lhs[ 1 ], lhs[ 2 ], lhs[ 3 ]);
    auto const ip_right = std::make_tuple(rhs[ 0 ], rhs[ 1 ], rhs[ 2 ], rhs[ 3 ]);

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
                     return ip.front() == octet;
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
                     return ip[ 0 ] == octet1 && ip[ 1 ] == octet2;
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
                                        [ &octet ](auto ip_oct)
                                        {
                                            return ip_oct == octet;
                                        });
                 });
    return pool;
}
