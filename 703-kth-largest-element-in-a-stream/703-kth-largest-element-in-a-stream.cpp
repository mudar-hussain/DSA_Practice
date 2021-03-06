//2nd Approach (1 queue)

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pqmin;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto n:nums){
            pqmin.push(n);
            if(pqmin.size()>k)
                pqmin.pop();
        }
    }
    
    int add(int val) {
        pqmin.push(val);
        if(pqmin.size()>k)
            pqmin.pop();
        return pqmin.top();
    }
};

//1st Approach (2 QUEUE)


// class KthLargest {
//     int kk;
//     priority_queue<int, vector<int>, greater<int>> pqmin;
//     priority_queue<int> pqmax;
// public:
//     KthLargest(int k, vector<int>& nums) {
//         kk = k;
//         if(nums.size()>0){
//             sort(nums.begin(), nums.end(), greater<int>());
//             for(int i = 0; i<nums.size(); i++){
//                 if(i<k)
//                     pqmin.push(nums[i]);
//                 else 
//                     pqmax.push(nums[i]);
//             }
//         }
//     }
    
//     int add(int val) {
//         if(pqmin.size()<kk)
//             pqmin.push(val);
//         else if(val>pqmin.top()){
//             pqmax.push(pqmin.top());
//             pqmin.pop();
//             pqmin.push(val);
//         }else{
//             pqmax.push(val);
//         }
//         return pqmin.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */