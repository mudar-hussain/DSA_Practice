class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]-mid > k)
                high = mid-1;
            else 
                low = mid+1;
        }
        return low+k;
    }
};