class SmallestInfiniteSet {
    vector<int> v;
    int smallest, temp;
public:
    SmallestInfiniteSet() {
        v.resize(1002, 1);
        smallest = 1;
    }
    
    int popSmallest() {
        v[smallest] = 0;
         temp = smallest;
        smallest++;
        
        while(v[smallest] != 1){
            smallest++;
        }
        
        return temp;
    }
    
    void addBack(int num) {
        v[num] = 1;
        if(num<smallest)
            smallest = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */