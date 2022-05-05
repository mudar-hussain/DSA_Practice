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
    vector<int> solve(TreeNode *root, int &ans){
        if(root == NULL) return {1,0,INT_MAX, INT_MIN};
        if(root->left == NULL && root->right == NULL) return {1,root->val,root->val, root->val};
        
        vector<int> l = solve(root->left,ans);
        vector<int> r = solve(root->right,ans);
        
        if(l[0] && r[0]){
            if(root->val > l[3] && root->val < r[2]){
                int x = l[2];
                int y = r[3];
                if(x == INT_MAX) x = root->val;
                if(y == INT_MIN) y = root->val;
                ans = max(ans, root->val+l[1]+r[1]);
                return {1, root->val+l[1]+r[1], x, y};
                
            }
        }
        ans = max(ans, max(l[1],r[1]));
        return {0, max(l[1],r[1]), 0,0};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        vector<int> aa = solve(root, ans);
        
        return ans<0? 0:ans;
    }
};