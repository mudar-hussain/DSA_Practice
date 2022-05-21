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
    Node* graph(Node *node, vector<Node *> &mp){
        Node *root = new Node(node->val);
        mp[node->val] = root;
        for(auto n: node->neighbors){
            if(mp[n->val] == NULL){
                root->neighbors.push_back(graph(n, mp));
            }else{
                root->neighbors.push_back(mp[n->val]);
            }
        }
        
        
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        vector<Node *> mp(101, NULL);
        return graph(node, mp);
    }
};


















