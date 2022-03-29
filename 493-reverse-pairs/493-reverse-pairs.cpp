class Solution {
public:
    //2nd Approach
int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
    
    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size() - 1);
    }
    
    
    
    //1st Approach
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     vector<int> not_valid;
    //     for(int i = 0; i<n-1; i++){
    //         int x = count;
    //         if(find(not_valid.begin(), not_valid.end(), nums[i]) == not_valid.end()){
    //             if(nums[i]>0){
    //                 for(int j = i+1; j<n; j++){
    //                         if(nums[i]>nums[j] && 1l * nums[i]> 1l * 2*nums[j]) 
    //                             count++;
    //                     }
    //             }else if(nums[i]<0){
    //                  for(int j = i+1; j<n; j++){
    //                         if(nums[i]<=nums[j] && 1l * nums[i]> 1l * 2*nums[j]) 
    //                             count++;
    //                     }
    //             }
    //         }
    //         if(x==count) 
    //              not_valid.push_back(nums[i]);
    //     }
    //     return count;
    // }
};