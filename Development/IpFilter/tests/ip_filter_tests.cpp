#include "ip_filter.h"
#include "ip_pool.h"

#include <gtest/gtest.h>

namespace tests
{
IpAddress const ip_0 = {"153", "130", "177", "64"};
IpAddress const ip_1 = {"222", "115", "157", "64"};
IpAddress const ip_2 = {"222", "130", "177", "64"};
IpAddress const ip_3 = {"222", "168", "177", "64"};

TEST(FilterTest, Comparator)
{
    EXPECT_TRUE(is_ip_greater(ip_1, ip_0));
    EXPECT_TRUE(is_ip_greater(ip_2, ip_1));
    EXPECT_TRUE(is_ip_greater(ip_3, ip_2));
}

IpPool const pool_for_tests {ip_2, ip_0, ip_3, ip_1};

TEST(FilterTest, SortIpPool)
{
    auto p {pool_for_tests};
    sort_ip_addresses(p);

    EXPECT_EQ(ip_3, p[ 0 ]);
    EXPECT_EQ(ip_2, p[ 1 ]);
    EXPECT_EQ(ip_1, p[ 2 ]);
    EXPECT_EQ(ip_0, p[ 3 ]);
}

IpPool read_ip_pool_from_lines(std::vector<std::string> const& lines)
{
    IpPool pool;
    for(auto const& line: lines)
    {
        std::vector<std::string> v = split_string(line, '\t');
        pool.push_back(split_string(v.at(0), '.'));
    }
    return pool;
}

TEST(FilterTest, SortOrigPool)
{
    IpPool p = read_ip_pool_from_lines(lines_from_cin);
    sort_ip_addresses(p);

    IpAddress first_ip = {"222", "173", "235", "246"};
    EXPECT_EQ(first_ip, p[ 0 ]);
}

TEST(FilterTest, FilterIp)
{
    IpPool p = read_ip_pool_from_lines(lines_from_cin);
    sort_ip_addresses(p);

    auto p_fxxx        = filter_ip_addresses(p, 1);
    IpAddress first_ip = {"1", "231", "69", "33"};

    EXPECT_EQ(first_ip, p_fxxx.front());
}

TEST(FilterTest, FilterIp2)
{
    IpPool p = read_ip_pool_from_lines(lines_from_cin);
    sort_ip_addresses(p);

    auto p_ffxx        = filter_ip_addresses(p, 46, 70);
    IpAddress first_ip = {"46", "70", "225", "39"};

    EXPECT_EQ(first_ip, p_ffxx.front());
}

TEST(FilterTest, FilterAnyIp)
{
    IpPool p = read_ip_pool_from_lines(lines_from_cin);
    sort_ip_addresses(p);

    auto p_any         = filter_any_octet(p, 46);
    IpAddress first_ip = {"186", "204", "34", "46"};

    EXPECT_EQ(first_ip, p_any.front());
}

} // namespace tests
