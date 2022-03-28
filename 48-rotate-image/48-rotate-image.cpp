class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<i; j++){
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }
        // for(int i = 0; i<n; i++)
        //     reverse(matrix[i].begin(), matrix[i].end());
        
        int b = 0;
        cout<<matrix[0][0];
        for(int i = 0,j = n-1; i<n/2; i++, j--){
            for(int zn = i, nz = j; zn<n-1-i; zn++,nz--){
                swap(matrix[i][zn], matrix[zn][j]);
                cout<<matrix[i][zn];
                swap(matrix[i][zn], matrix[j][nz]);
                cout<<matrix[i][zn];
                swap(matrix[i][zn], matrix[nz][i]);
                cout<<matrix[i][zn];
            }
            cout<<"   ";
            
        }
        
    }
};