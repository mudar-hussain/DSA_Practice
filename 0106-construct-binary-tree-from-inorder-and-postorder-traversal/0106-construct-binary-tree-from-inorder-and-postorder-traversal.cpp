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
    unordered_map<int, int> um;
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &idx, int left, int right){
        if(left>right || idx<0)
            return NULL;
        int mid = um[postorder[idx]];
        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;
        root->right = solve(inorder, postorder, idx, mid+1, right);
        root->left = solve(inorder, postorder, idx, left, mid-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        int idx = n-1;
        
        for(int i = 0; i<n; i++){
            um[inorder[i]] = i;
        }
        
        return solve(inorder, postorder, idx, 0, n-1);
        
    }
};