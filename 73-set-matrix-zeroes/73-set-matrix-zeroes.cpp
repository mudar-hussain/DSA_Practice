class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row,col;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(!count(row.begin(), row.end(), i))
                        row.push_back(i);
                    if(!count(col.begin(), col.end(), j))
                        col.push_back(j);
                }
            }
        }
        for(int i:row){
            for(int j = 0; j<n; j++){
                matrix[i][j] = 0;
            }
        }
        for(int i:col){
            for(int j = 0; j<m; j++){
                matrix[j][i] = 0;
            }
        }
        
            
        
        
    }
};