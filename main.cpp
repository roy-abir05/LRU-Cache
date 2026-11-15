#include "LRUCache.hpp"
#include <string>
#include <iostream>
#include <cassert>

int main()
{
    const LRUCache<int, std::string> c1(3);
    LRUCache<int, std::string> c2(0);
    LRUCache<int, std::string> c3(1);

    std::cout << c1.size() << " " << c2.size() << std::endl;
    std::cout << c1.empty() << " " << c2.empty() << std::endl;
    auto v = c2.get(69);
    std::cout << v.has_value() << std::endl;

    LRUCache<int, int> cache(3);
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    auto a = cache.get(1);
    auto b = cache.get(2);

    cache.put(4, 400);

    assert(!cache.get(3).has_value());
    assert(cache.size() == 3);

    c2.put(1, "100");
    assert(c2.size() == 0);

    c3.put(1, "100");
    c3.put(1, "200");
    assert(c3.size() == 1);
    assert(c3.get(1)=="200");

    LRUCache<int, int> cache2(3);

    cache2.put(1, 100);
    cache2.put(2, 200);
    cache2.put(3, 300);

    cache2.get(1);
    cache2.get(2);

    cache2.put(4, 400);

    assert(!cache2.get(3).has_value());
    assert(cache2.get(1).has_value());
    assert(cache2.get(2).has_value());
    assert(cache2.get(4).has_value());


    LRUCache<int, std::string> original(3);

    original.put(1, "one");
    original.put(2, "two");

    LRUCache<int, std::string> copy = original;

    assert(copy.size() == 2);

    assert(copy.get(1) == "one");
    assert(copy.get(2) == "two");

    copy.put(3, "three");
    assert(!original.get(3).has_value());

    assert(copy.size() == 3);
    assert(original.size() == 2);

    copy = original;
    assert(copy.size() == 2);

    original = original;
    assert(original.size() == 2);

    return 0;
}
