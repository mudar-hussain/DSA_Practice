/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve(TreeNode *root, string &ans){
        if(root == NULL) {
            ans += "#,";
            return;
        }
        ans += to_string(root->val) + ",";
        solve(root->left, ans);
        solve(root->right, ans);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeTree(data, index);
    }
    TreeNode * deserializeTree(string data, int &idx){
        if(idx >= data.length()-1) return nullptr;
        TreeNode *node = nullptr;
        string s = "";
        while(data[idx]!=','){
            s += data[idx];
            idx++;
        }
        if(s == "#"){
            return nullptr;
            
        }else{
            node = new TreeNode(stoi(s));
            
        }
        
        node->left = deserializeTree(data, ++idx);
        node->right = deserializeTree(data, ++idx);
        return node;
    }
};





















// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));