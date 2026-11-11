#include "LRUCache.hpp"
#include <string>
#include <iostream>

template <typename K, typename V>
LRUCache<K, V>::LRUCache(std::size_t capacity)
: _capacity(capacity){}

template <typename K, typename V>
std::size_t LRUCache<K, V>::size() const{
    return (this->_list).size();
}

template <typename K, typename V>
bool LRUCache<K, V>::empty() const{
    return (this->size())==0;
}

int main()
{
    LRUCache<int, std::string> c1(3);
    LRUCache<int, std::string> c2(0);

    std::cout << c1.size() << " " << c2.size() << std::endl;
    std::cout << c1.empty() << " " << c2.empty() << std::endl;
    return 0;
}