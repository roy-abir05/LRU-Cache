#pragma once
#include <string>
#include <optional>

template <typename K, typename V>
LRUCache<K, V>::LRUCache(std::size_t capacity)
: _capacity(capacity){}

template <typename K, typename V>
std::optional<V> LRUCache<K, V>::get(const K &key)
{
    auto it = _ump.find(key);
    if (it==_ump.end()) return {};

    _list.splice(_list.begin(), _list, it->second);

    return it->second->second;
}

template <typename K, typename V>
std::size_t LRUCache<K, V>::size() const{
    return (this->_list).size();
}

template <typename K, typename V>
bool LRUCache<K, V>::empty() const{
    return size()==0;
}
