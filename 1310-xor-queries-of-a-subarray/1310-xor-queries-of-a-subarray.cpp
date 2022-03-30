struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> um;
        um[0] = nums[0];
        for(int i = 1; i<n; i++){
            um[i] = um[i-1]^nums[i];
        }
        for(auto q:queries){
            int i = q[0];
            int j = q[1];
            if(i==0){
                ans.push_back(um[j]);
            }else{
                ans.push_back(um[i-1]^um[j]);
            } 
        }
        return ans;
    }
};