class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
//         int b = 0;
//         for(int lr = 0, tb = n-1; lr<n-1; lr++,tb--){
//             for(int rl = n-1, bt = 0; rl>0; rl--,bt++){
//                 swap(matrix[lr][bt], matrix[tb][lr]);
//                 swap(matrix[lr][tb], matrix[tb][rl]);
//                 swap(matrix[lr][bt], matrix[bt][lr]);
//             }
            
//             // cout<<j;
//         }
        
    }
};