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
    using node_itr = typename std::list<node>::iterator;

    std::size_t _capacity;
    std::list<node> _list;
    std::unordered_map<K, node_itr> _ump;

public:
    explicit LRUCache(std::size_t capacity);
    LRUCache(const LRUCache& other);
    void swap(LRUCache& other) noexcept;
    LRUCache& operator=(const LRUCache& other);
    std::optional<V> get(const K &key);
    void put(const K &key, const V &value);
    bool erase(const K &key);
    std::size_t size() const;
    bool empty() const;
};

#include "LRUCache.tpp"