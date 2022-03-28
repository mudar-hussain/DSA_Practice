class Solution {
public:
      long long int merge(vector<int>& arr, int l, int mid, int r){
   
        int n1 = mid-l+1;
        int n2 = r-mid;
        
        int a1[n1], a2[n2];
        long long int ans = 0;
        
        for(int i = 0; i<n1; i++){
            a1[i] = arr[l+i];
        }
        for(int i = 0; i<n2; i++){
            a2[i] = arr[mid+1+i];
        }
        int i = 0, j = 0, k = l;
        while(i<n1 && j<n2){
            if(a1[i]<=a2[j]){
                arr[k] = a1[i];
                i++;
            }else {
                arr[k] = a2[j];
                j++;
                ans += (n1-i);
            }
            k++;
        }
        while(i<n1){
            arr[k] = a1[i];
            i++;k++;
        }
        while(j<n2){
            arr[k] = a2[j];
            j++;k++;
        }
        return ans;
    }


 long long int mergeSort(vector<int>& arr, int l, int r){
    long long int ans = 0;
    if(l<r){
        long long mid = l+(r-l)/2;
        ans += mergeSort(arr,l,mid);
        ans += mergeSort(arr,mid+1,r);
        
        ans += merge(arr,l,mid,r);
        
    }
    return ans;
}
    bool isIdealPermutation(vector<int>& nums) {
        long long int count = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) count++;
            
            // for(int j = 0; j<nums.size()-1; j++)
            //     if(nums[i]>nums[j]) count--;
        }
        count -= mergeSort(nums, 0, nums.size()-1);
        return !count;
        
    }
};