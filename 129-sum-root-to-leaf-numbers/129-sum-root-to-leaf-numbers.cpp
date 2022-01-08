class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right)return root->val;
        int sum=0;
        findSum(root,0,sum);
        return sum;
    }
    void findSum(TreeNode*root,int rNum,int &sum)
    {
        if(!root) return;
        int i=rNum*10+root->val;
        findSum(root->left,i,sum);
        findSum(root->right,i,sum);
        if(!root->left&&!root->right)sum+=i;
    }
};