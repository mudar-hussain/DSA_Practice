class MyHashSet {
   
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        int x = key%100;
        if(!contains(key)){
            arr[x].push_back(key);
        }
    }
    
    void remove(int key) {
        auto it = find(arr[hkey(key)].begin(),arr[hkey(key)].end(),key);
        if(it!=arr[hkey(key)].end())
       {
           arr[hkey(key)].erase(it);
       }
    }
    
    bool contains(int key) {
        auto it = find(arr[hkey(key)].begin(),arr[hkey(key)].end(),key);
        if(it!=arr[hkey(key)].end())
       {
           return true;
       }
        return false;
    }
    int hkey(int x)
    {
        return x%100;
    }
    private:
        vector<int>arr[100];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
