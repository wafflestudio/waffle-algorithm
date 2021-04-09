class MyHashMap {
public:
    int *hash_array;
    const int div = 1000003; //prime number
    
    /** Initialize your data structure here. */
    MyHashMap() {
        hash_array = (int*)malloc(1000001 * sizeof(int));
        for (int i=0; i<1000001; i++) {
            hash_array[i] = -1;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hash_array[key % div] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hash_array[key % div];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash_array[key%div] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */