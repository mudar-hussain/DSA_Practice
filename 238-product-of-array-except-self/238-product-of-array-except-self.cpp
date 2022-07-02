class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
	int z_index = -1;
	vector<int> ans(n, 0);
	for(int i = 0; i<n; i++){
        if(nums[i] == 0){
            if(z_index != -1)	return ans;
            z_index = i;
        }
    }

    if(z_index != -1){
        int l = 1, r = 1;
        for(int i = 0; i<z_index; i++)		l *= nums[i];
        for(int i = z_index+1; i<n; i++)	r *= nums[i];
        ans[z_index] = l*r;
        return ans;
    }
    long product = 1;
    for(int i = 0; i<n; i++)		product *= nums[i];
    for(int i = 0; i<n; i++)		ans[i] = product/nums[i];
    return ans;

    }
};