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
    // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//     bool  dfs(TreeNode *root, int k, int cnt){
//         if(k == 0) return true;
        
//         if(root == NULL || cnt == 2) return false;
        
//         return (findTarget(root->left, k, cnt) || findTarget(root->right, k, cnt) || findTarget(root->left, k-root->val, cnt+1) || findTarget(root->right, k-root->val, cnt+1));
//     }
    
   // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    void inorder(TreeNode *root, vector<int> &v){
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        vector<int> v;
        inorder(root, v);
        int l = 0, r = v.size()-1;
        while(l<r){
            if(v[l]+v[r] == k) 
                return true;
            else if(v[l]+v[r] < k)
                l++;
            else 
                r--;
        }
        return false;
        
    }
    //1st Approach
//     void st(TreeNode *root, stack<TreeNode *> &s, int direction){
//         if(!root) return;
//         s.push(root);
//         if(direction){ 
//             while(root->left){
//                 root = root->left;
//                 s.push(root);
//             }
//         }else{
//             while(root->right){
//                 root = root->right;
//                 s.push(root);
//             }
//         }
        
//     }
//     bool findTarget(TreeNode* root, int k) {
//         if(!root) return false;
//         stack<TreeNode*> mins, maxs;
//         st(root,mins, 1);
//         st(root,maxs, 0);
//         while(!mins.empty() && !maxs.empty() && mins.top()->val < maxs.top()->val){
//             int x = mins.top()->val;
//             int y = maxs.top()->val;
//             if(x+y == k) return true;
//             else if(x+y < k) {
//                 TreeNode *temp = mins.top();
//                 mins.pop();
//                 st(temp->right, mins, 1);
//             }
//             else{
//                 TreeNode *temp = maxs.top();
//                 maxs.pop();
//                 st(temp->left, maxs, 0);
//             }
             
//         }
//         return false;
        
//     }
};










