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
    int ans = -1, count = 0;
public:
    //  vector<int> ans;
    // void solve(TreeNode *root, int k){
    //     if(ans.size()>=k) return;
    //     if(!root) return;
    //     solve(root->left, k);
    //     ans.push_back(root->val);
    //     solve(root->right, k);
    // }
    int kthSmallest(TreeNode* root, int k) {
        if(!root ) return ans;
        kthSmallest(root->left,k);
        count++;
        if(count==k) {
            ans = root->val;
            return ans;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};