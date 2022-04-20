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
    //2nd Approach
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string s = "";
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});
        q.push({NULL,""});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode *temp = curr.first;
            string ss = curr.second;
            if(temp != NULL){
                if(!temp->left && !temp->right){
                    ans.push_back(ss);
                }else{
                    if(temp->left) q.push({temp->left, ss + "->" + to_string(temp->left->val)});
                    if(temp->right) q.push({temp->right, ss + "->" + to_string(temp->right->val)});
                }
            }else if(!q.empty()) q.push({NULL,""});
        }
        
        return ans;
    }
    //1st Approach
    // vector<string> ans;
    // void rootToLeaf(TreeNode *root, string s){
    //     if(!root) return;
    //     s.append("->"+to_string(root->val));
    //     if(!root->left && !root->right) {
    //         s.erase(s.begin()+0,s.begin()+2);
    //         ans.push_back(s);
    //         return;
    //     }
    //     rootToLeaf(root->left,s);
    //     rootToLeaf(root->right,s);
    // }
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     string s = "";
    //     rootToLeaf(root,s);
    //     return ans;
    // }
};