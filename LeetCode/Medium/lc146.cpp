#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <list>
#include <unordered_map>
#include <iterator>
using namespace std;

/* Solution Class */
class LRUCache {
private:
    list<pair<int,int>> data;
    unordered_map<int,list<pair<int,int>>::iterator> hash; 
    int capacity;

    void moveToHead(int key, int value) {
        if (hash.count(key))
            data.erase(hash[key]);
        data.emplace_front(key, value);
        hash[key] = data.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
    }

    int get(int key) {
        if (!hash.count(key))
            return -1;
        int value = hash[key]->second;
        moveToHead(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (hash.count(key) == 0 && data.size() == capacity) {
            int LRUKey = data.back().first;
            data.erase(hash[LRUKey]);
            hash.erase(LRUKey);
        }
        moveToHead(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[]) {
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    vector<int> ret;

    /* Input & Output */
    obj->put(1, 1);
    obj->put(2, 2);
    ret.push_back(obj->get(1));
    obj->put(3, 3);
    ret.push_back(obj->get(2));
    obj->put(4, 4);
    ret.push_back(obj->get(1));
    ret.push_back(obj->get(3));
    ret.push_back(obj->get(4));

    /* Answer */
    vector<int> answer = {1, -1, -1, 3, 4};

    /* Check */
    assert(ret == answer);
    puts("PASS!");

    return 0;
}
