// Problem link: https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(1) for both get() and put()
// Space complexity = O(n) ; n = capacity of LRU cache
class LRUCache {
    size_t capacity_;

    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> cache;

    void moveToFront(int key) {
        if (map[key] == cache.begin()) {
            // if already at front then don't do any opeartion further
            return;
        }
        int value = map[key]->second;
        pair<int, int> data(key, value);

        cache.erase(map[key]);
        cache.push_front(data);

        map[key] = cache.begin();
    }

    void deleteLRU() {
        int last_key = cache.back().first;
        map.erase(last_key);

        cache.pop_back();
    }

   public:
    LRUCache(int capacity) {
        this->capacity_ = capacity;
    }

    int get(int key) {
        bool key_exist = map.count(key);
        if (!key_exist) {
            return -1;
        }

        int value = map[key]->second;
        moveToFront(key);

        return value;
    }

    void put(int key, int value) {
        pair<int, int> data(key, value);

        bool key_already_exist = map.count(key);
        if (key_already_exist) {
            map[key]->second = value;
            moveToFront(key);

            return;
        }

        cache.push_front(data);
        map.insert({key, cache.begin()});

        if (cache.size() > this->capacity_) {
            deleteLRU();
        }
    }
};

int main() {
}
