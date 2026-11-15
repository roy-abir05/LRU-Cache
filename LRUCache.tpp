#pragma once

template <typename K, typename V>
LRUCache<K, V>::LRUCache(std::size_t capacity)
: _capacity(capacity){}

template <typename K, typename V>
LRUCache<K, V>::LRUCache(const LRUCache& other)
: _capacity(other._capacity), _list(other._list)
{
    for (auto it = this->_list.begin(); it != this->_list.end(); ++it)
    {
        this->_ump.emplace(it->first, it);
    }
}

template <typename K, typename V>
std::optional<V> LRUCache<K, V>::get(const K &key)
{
    auto it = _ump.find(key);
    if (it==_ump.end()) return {};

    _list.splice(_list.begin(), _list, it->second);

    return it->second->second;
}

template <typename K, typename V>
void LRUCache<K, V>::put(const K &key, const V &value)
{
    if (_capacity==0) return;

    auto it = _ump.find(key);

    if (it==_ump.end())
    {
        if (size()==_capacity)
        {
            _ump.erase(_list.back().first);
            _list.pop_back();
        }
        _list.emplace_front(key, value);
        _ump.emplace(key, _list.begin());
    }
    else
    {
        it->second->second = value;
        _list.splice(_list.begin(), _list, it->second);
    }
}

template <typename K, typename V>
bool LRUCache<K, V>::erase(const K &key)
{
    auto it = _ump.find(key);
    if (it==_ump.end()) return false;

    _list.erase(it->second);
    _ump.erase(it);
    return true;
}

template <typename K, typename V>
std::size_t LRUCache<K, V>::size() const{
    return _list.size();
}

template <typename K, typename V>
bool LRUCache<K, V>::empty() const{
    return size()==0;
}
