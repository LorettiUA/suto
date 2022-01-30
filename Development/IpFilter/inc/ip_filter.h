#include <functional>
#include <string>
#include <vector>

using IpAddress = std::vector<std::string>;
using IpPool    = std::vector<IpAddress>;

IpPool read_ip_pool();

std::vector<std::string> split_string(const std::string& str, char d);

void print_ip_pool(IpPool const& ip_pool);

void sort_ip_addresses(IpPool& ip_pool);

bool is_ip_greater(IpAddress const& lhs, IpAddress const& rhs);

IpPool filter_ip_addresses(IpPool const& ip_pool, int octet);

IpPool filter_ip_addresses(IpPool const& ip_pool, int octet1, int octet2);

IpPool filter_any_octet(IpPool const& ip_pool, int octet);
