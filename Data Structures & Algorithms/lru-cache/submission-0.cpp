
class LRUCache {
private:
    int capacity;

    // Stores {key, value}
    list<pair<int, int>> cache;

    // Maps key to its position in the list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move the accessed key to the front
        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, remove its old entry
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        // Insert the key-value pair at the front
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Remove least recently used key if capacity is exceeded
        if (cache.size() > capacity) {
            int lruKey = cache.back().first;

            cache.pop_back();
            mp.erase(lruKey);
        }
    }
};

