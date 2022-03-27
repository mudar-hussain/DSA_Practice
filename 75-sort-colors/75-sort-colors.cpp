class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0:swap(nums[low++], nums[mid++]);
                        break;
                case 1:mid++; break;
                case 2:swap(nums[mid], nums[high--]); 
                        break;
            }
        }
        
//         int n = nums.size();
//         int z = 0, t = n-1;
//         for(int i = 0; i<n && i<=t; i++){
//             if(nums[i]==0){
//                 swap(nums[i], nums[z]);
//                 z++;
//             }else if(nums[i]==2){
//                 swap(nums[i], nums[t]);
//                 t--;
//                 if(nums[i] == 0 || nums[i] == 2) i--;
//             }
            
//         }
        
    }
};