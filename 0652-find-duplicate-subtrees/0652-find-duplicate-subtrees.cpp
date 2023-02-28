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
    vector<TreeNode*> ans;
    unordered_map<string, int> um;
//     unordered_map<int, vector<TreeNode*>> ansMap;
//     bool isSame(TreeNode* a, TreeNode* b){
//         if(a == NULL && b == NULL)
//             return true;
//         if(a == NULL || b == NULL)
//             return false;
//         if(a->val != b->val)
//             return false;
//         return isSame(a->left, b->left) && isSame(a->right, b->right);
//     } 
    
//     bool isExist(TreeNode* root, vector<TreeNode*> v){
//         for(auto i: v){
//             if(isSame(root, i))
//                 return true;
//         }
//         return false;
//     }
    
//     void solve(TreeNode* root){
//         if(root == NULL)
//             return;
//         if(um[root->val].size() != 0){
//             if(ansMap[root->val].size() == 0 || !isExist(root, ansMap[root->val])){
//                 for(auto i: um[root->val]){
//                     if(isSame(root, i)){
//                         ans.push_back(root);
//                         ansMap[root->val].push_back(root);
//                         break;
//                     }
//                 }
//             }
            
//         }
//         um[root->val].push_back(root);
//         solve(root->left);
//         solve(root->right);
        
//     }
    
    string inorder(TreeNode* root){
        if(root == NULL)
            return "";
        
        string str = "(";
        str += inorder(root->left);
        str += to_string(root->val);
        str += inorder(root->right);
        str += ")";
        
        um[str]++; 
        
        if(um[str] == 2)
            ans.push_back(root);
        
        return str;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inorder(root);
        return ans;
    }
};








