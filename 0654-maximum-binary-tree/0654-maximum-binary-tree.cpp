/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int s, int e) {
        if(e-s < 0)
            return NULL;
        
        int maxi = INT_MIN;
        int maxIdx = -1;
        for(int i = s; i<=e; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIdx = i;
            }
        }
        if(maxIdx == -1)
            return NULL;
        TreeNode *root = new TreeNode(nums[maxIdx]);
        root->left = solve(nums, s, maxIdx-1);
        root->right = solve(nums, maxIdx+1, e);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
        
        return solve(nums, 0, nums.size()-1);
    }
};








