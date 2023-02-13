class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        int total = n*m;
        n--,m--;
        int lowN = 0, lowM = 0;
        
        vector<int> ans;
        
        while(count<total){
            //left to right
            for(int j = lowM; j<=m && count<total; j++){
                ans.push_back(matrix[lowN][j]);
                count++;
            }
            lowN++;
            
            //top to bottom
            for(int i = lowN; i<=n && count<total; i++){
                ans.push_back(matrix[i][m]);
                count++;
            }
            m--;
            
            //right to left
            for(int j = m; j>=lowM && count<total; j--){
                ans.push_back(matrix[n][j]);
                count++;
            }
            n--;
            
            //bottom to top       
            for(int i = n; i>=lowN && count<total; i--){
                ans.push_back(matrix[i][lowM]);
                count++;
            }
            lowM++;
        }
        return ans;
    }
};








