class LRUCache {
private:
    std::unordered_map<int, list<pair<int, int>>::iterator> map;  // key, pos
    list<pair<int, int>> lst; // {key, val}
    int _capacity;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        // put key to the front 
        lst.splice(lst.begin(), lst, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        // exist
        if (map.count(key)) {
            // update val of this key
            map[key]->second = value;
            lst.splice(lst.begin(), lst, map[key]);
        } else {
            // check size 
            if (lst.size() == _capacity) {
                map.erase(lst.back().first);
                lst.pop_back();
            }
            // lst push lastest key and value
            lst.push_front({key, value});
            map[key] = lst.begin();
        }
    }
};