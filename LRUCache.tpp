#include "LRUCache.hpp"
#include <string>

template <typename K, typename V>
LRUCache<K, V>::LRUCache(std::size_t capacity)
: _capacity(capacity){}

template <typename K, typename V>
std::size_t LRUCache<K, V>::size() const{
    return (this->_list).size();
}

template <typename K, typename V>
bool LRUCache<K, V>::empty() const{
    return size()==0;
}
