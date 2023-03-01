class Solution {
    vector<int> v;
    void merge(vector<int> &nums, int l, int mid, int h){
        
        int i = l;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid && j<=h){
            if(nums[i]<=nums[j]){
                v[k++] = nums[i++];
            }else{
                v[k++] = nums[j++];
            }
        }
        while(i<=mid){
            v[k++] = nums[i++];
        }
        
        while(j<=h){
            v[k++] = nums[j++];
        }
        
        for(int i = 0; i<k; i++){
            nums[l+i] = v[i];
        }
    }
    
    void mergeSort(vector<int> &nums, int l, int h){
        if(l>=h)
            return;
        int mid = l + (h-l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, h);
        merge(nums, l, mid, h);
        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        v.resize(nums.size());
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};