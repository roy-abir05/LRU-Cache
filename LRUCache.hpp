#pragma once

#include <list>
#include <unordered_map>
#include <optional>
#include <utility>
#include <cstddef>

template <typename K, typename V>
class LRUCache
{

    using node = std::pair<const K, V>;
    using node_itr = std::list<node>::iterator;

    std::list<node> _list;
    std::unordered_map<K, node_itr> _ump;
    std::size_t _capacity;

public:
    explicit LRUCache(std::size_t capacity);
    std::optional<V> get(const K &key);
    void put(const K &key, const V &value);
    bool erase(const K &key);
    std::size_t size() const;
    bool empty() const;
};

#include "LRUCache.tpp"