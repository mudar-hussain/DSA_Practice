class Solution {
public:
    bool isPeak(vector<vector<int>>& mat, int n, int m, int i, int j){
        if(i-1>=0 && mat[i][j]<mat[i-1][j])
            return false;
        if(j-1>=0 && mat[i][j]<mat[i][j-1])
            return false;
        if(i+1<n && mat[i][j]<mat[i+1][j])
            return false;
        if(j+1<m && mat[i][j]<mat[i][j+1])
            return false;
        
        return true;
    }
    void adjPeak(vector<vector<int>>& mat, int n, int m, int& i, int& j){
        int maxi = mat[i][j];
        int mi = i, mj = j;
        if(i-1>=0 && maxi<mat[i-1][j]){
            maxi = mat[i-1][j];
            mi = i-1;
            mj = j;
        }
        if(j-1>=0 && maxi<mat[i][j-1]){
            maxi = mat[i-1][j];
            mi = i;
            mj = j-1;
        }
        if(i+1<n && maxi<mat[i+1][j]){
            maxi = mat[i+1][j];
            mi = i+1;
            mj = j;
        }
        if(j+1<m && maxi<mat[i][j+1]){
            maxi = mat[i][j+1];
            mi = i;
            mj = j+1;
        }
        
        if(mi == i && mj == j){
            i = -1;
            j = -1;
        }else{
            i = mi;
            j = mj;
        }
            
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 1 && m == 1)
            return {0,0};
        int i = 0, j = 0;
        while(i<n && j<m){
            if(isPeak(mat, n, m, i, j)){
                return {i,j};
            }
            int tempi=i, tempj=j;
            adjPeak(mat, n, m, i, j);
            if(i == -1 && j == -1){
                i = tempi;
                j = tempj;
                if(j != m-1) i++;
                else i++;
            }
        }
        return {-1,-1};
    }
};









