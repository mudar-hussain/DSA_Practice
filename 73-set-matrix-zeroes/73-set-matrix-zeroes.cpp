class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool frz = false, fcz = false;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) frz = true;
                    if(j == 0) fcz = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = m-1; i>0; i--){
            for(int j = n-1; j>0; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(frz) {
            for(int i = 0; i < n; i++)
                matrix[0][i] = 0;
        }
        if(fcz) {
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
        
        // vector<int> row,col;
        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(matrix[i][j] == 0){
        //             if(!count(row.begin(), row.end(), i))
        //                 row.push_back(i);
        //             if(!count(col.begin(), col.end(), j))
        //                 col.push_back(j);
        //         }
        //     }
        // }
        // for(int i:row){
        //     for(int j = 0; j<n; j++){
        //         matrix[i][j] = 0;
        //     }
        // }
        // for(int i:col){
        //     for(int j = 0; j<m; j++){
        //         matrix[j][i] = 0;
        //     }
        // }
        
            
        
        
    }
};