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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        queue<pair<TreeNode*, double>> q;
        
        q.push({root, 0});
        double ans = INT_MIN;
        double size, left, right;
        TreeNode* temp;
        while(!q.empty()){
            size = q.size();
            left = q.front().second;
            while(size--){
                temp = q.front().first;
                right = q.front().second;
                q.pop();
                if(temp->left)
                    q.push({temp->left, (right-left)*2});
                if(temp->right)
                    q.push({temp->right, (right-left)*2+1});
            }
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};










