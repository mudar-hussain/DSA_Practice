/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *CG(Node *node, vector<Node *> &mp){
        
        Node *root = new Node(node->val);
        mp[root->val] = (root);
        
        vector<Node*> vec;
        
        for(auto n: node->neighbors){
            if(mp[n->val] == NULL)
                vec.push_back(CG(n, mp));
            else
                vec.push_back(mp[n->val]);
        }
        root->neighbors = vec;
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        vector<Node *> mp(101, NULL);
        
        return CG(node, mp);
    }
};












