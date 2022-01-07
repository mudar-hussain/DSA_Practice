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
    vector<string> ans;
    void rootToLeaf(TreeNode *root, string s){
        if(!root) return;
        s.append("->"+to_string(root->val));
        if(!root->left && !root->right) {
            s.erase(s.begin()+0,s.begin()+2);
            ans.push_back(s);
            return;
        }
        rootToLeaf(root->left,s);
        rootToLeaf(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        rootToLeaf(root,s);
        return ans;
    }
};