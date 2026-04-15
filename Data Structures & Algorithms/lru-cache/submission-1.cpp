class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> lst;
    int _cap;
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        // update to the front
        lst.splice(lst.begin(), lst, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        // if can find key, update value
        if (map.count(key)) {
            map[key]->second = value;
            lst.splice(lst.begin(), lst, map[key]);
        } else {
            // check size 
            if (lst.size() == _cap) {
                map.erase(lst.back().first);
                lst.pop_back();
            }
            lst.push_front({key, value});
            map[key] = lst.begin();
        }
    }
};