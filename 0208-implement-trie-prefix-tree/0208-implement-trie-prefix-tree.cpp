class TrieNode {
    public:
        bool isComplete;
        TrieNode *child[26];
    
        TrieNode(){
            isComplete = false;
            memset(child, 0, sizeof(child));
        }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch: word){
            if(node->child[ch-'a'] == NULL)
                node->child[ch-'a'] = new TrieNode();
            node = node->child[ch-'a'];
        }
        node->isComplete = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch: word){
            if(node->child[ch-'a'] == NULL)
                return false;
            node = node->child[ch-'a'];
        }
        return node->isComplete;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch: prefix){
            if(node->child[ch-'a'] == NULL)
                return false;
            node = node->child[ch-'a'];
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