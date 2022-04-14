class LRUCache {
    struct Node{
        int key, value;
        Node *prev, *next;
        
        Node(int k, int v){key = k; value = v;};
    };
    Node *head = new Node(0,0);
    Node *tail = new Node(0,0);
    unordered_map<int,Node*> map;
    int capacity;
public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node *data = map[key];
            
            remove(data);
            insert(data);
            
            return data->value;
        }else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            
            remove(map[key]);
            
        }else if(capacity == map.size()){
            
            //remove LRU 
            remove(tail->prev);
        }
        
        insert(new Node(key, value));
        
        
    }
    void remove(Node *node){
        map.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node *node){
        map[node->key] = node;
        Node *headNext = head->next;
        head->next = node;
        node->prev = head;
        
        node->next = headNext;
        headNext->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */