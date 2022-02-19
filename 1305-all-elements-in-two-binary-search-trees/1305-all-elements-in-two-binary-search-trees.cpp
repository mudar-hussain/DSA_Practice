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
    void pushleft(TreeNode *root, stack<TreeNode*> &s){
        if(root==NULL) return;
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        pushleft(root1, s1);
        pushleft(root2, s2);
        while(!s1.empty() && !s2.empty()){
            int x= s1.top()->val;
            int y = s2.top()->val;
            if(x<y){
                ans.push_back(x);
                TreeNode *temp = s1.top();
                s1.pop();
                pushleft(temp->right, s1);
            }
            else if(x>y){
                ans.push_back(y);
                TreeNode *temp = s2.top();
                s2.pop();
                pushleft(temp->right, s2);
            }
            else {
                ans.push_back(x);
                TreeNode *temp1 = s1.top();
                s1.pop();
                pushleft(temp1->right, s1);
                
                ans.push_back(y);
                TreeNode *temp = s2.top();
                s2.pop();
                pushleft(temp->right, s2);
            }
        }
        while(!s1.empty()){
            ans.push_back(s1.top()->val);
            TreeNode *temp = s1.top();
            s1.pop();
            pushleft(temp->right, s1);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            TreeNode *temp = s2.top();
            s2.pop();
            pushleft(temp->right, s2);
        }
        return ans;
    }
};