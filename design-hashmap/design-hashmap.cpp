class MyHashMap {
    vector<list<pair<int,int>>> v;
    int size;
public:
    MyHashMap() {
        size = 100;
        v.resize(size);
    }
    
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int i = hash(key);
        auto it = v[i].begin();
        while(it!=v[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    bool contains(int key){
        int i = hash(key);
        if(search(key) == v[i].end()) return false;
        return true;
    }
    
    void put(int key, int value) {
        
        int i = hash(key);
        remove(key);
        v[i].push_back({key,value});
        
    }
    
    int get(int key) {
        if(!contains(key)) return -1;
        return search(key)->second;
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        v[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */