class Solution {
public:
    //2nd Approach
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int sz = target.size();
        int k = 0;
        for(int i = 1; i<=n; i++){
            if(i == target[k]) {
                ans.push_back("Push");
                k++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(k == sz) break;
        }
        return ans;
    }
    //1st Approach
//     vector<string> buildArray(vector<int>& target, int n) {
//         vector<string> v;
//         int k = 0;
//         for(int i = 1; i<=n; i++){
//             if(k==target.size()) break;
//             v.push_back("Push");
//             if(i == target[k] && k<target.size()){
//                 k++;
//                 continue;
                
//             }else v.push_back("Pop");
//         }
//         return v;
//     }
};