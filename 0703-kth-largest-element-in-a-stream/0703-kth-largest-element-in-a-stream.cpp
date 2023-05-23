class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 1;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            pq.push(i);
        }
        size = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */