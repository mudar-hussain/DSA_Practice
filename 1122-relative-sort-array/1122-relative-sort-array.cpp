class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A1, vector<int>& A2) {
        vector<int> ans;
        
        int N = A1.size();
        unordered_map<int, int> um;
        for(int i: A1){
            um[i]++;
        }
        for(int i: A2){
            while(um[i]>0){
                ans.push_back(i);
                um[i]--;
            }
        }
        int ind = ans.size();
        for(int i = 0; i<N; i++){
            if(um[A1[i]]>0){
                ans.push_back(A1[i]);
                um[A1[i]]--;
            }
            
        }
        sort(ans.begin()+ind, ans.end());   
        
        return ans;
    }
};