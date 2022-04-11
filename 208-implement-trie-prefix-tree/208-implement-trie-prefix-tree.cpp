class Trie {
public:
    struct Node{
        Node *link[26] = {NULL};
        int we = 0;
    };
    
    bool isContainsKey(Node *node, char c){
        return (node->link[c - 'a'] != NULL);
    }
    Node *root;
    

    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i<word.length(); i++){
            if(!isContainsKey(node, word[i])){
                node->link[word[i]-'a'] = new Node;
            }
            node = node->link[word[i]-'a'];
            
        }
        node->we++;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i<word.length(); i++){
            if(!isContainsKey(node, word[i])){
                return false;
            }
            node = node->link[word[i]-'a'];
            
        }
        if(node->we>0) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!isContainsKey(node, prefix[i])){
                return false;
            }
            node = node->link[prefix[i]-'a'];
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */