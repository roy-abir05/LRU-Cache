#include "LRUCache.hpp"
#include <string>
#include <iostream>

int main()
{
    const LRUCache<int, std::string> c1(3);
    const LRUCache<int, std::string> c2(0);

    std::cout << c1.size() << " " << c2.size() << std::endl;
    std::cout << c1.empty() << " " << c2.empty() << std::endl;
    return 0;
}