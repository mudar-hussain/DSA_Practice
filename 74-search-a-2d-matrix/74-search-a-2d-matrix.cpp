class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = m*n-1;
        int mid;
        while(low<=high){
            mid = low+(high-low)/2;
            if(target<matrix[mid/m][mid%m]){
                high = mid-1;
            }else if(target>matrix[mid/m][mid%m]){
                low = mid+1;
            }else if(target == matrix[mid/m][mid%m]){
                return true;
            }
            
           
        }
        return false;
    }
};