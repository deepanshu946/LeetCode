class LRUCache {
public:
    class Node {
      public:
        int key;
      int val;
      Node * next;
      Node * prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;
    void deletenode(Node* n){
        n->next->prev=n->prev;
        n->prev->next=n->next;
        n->prev=NULL;
        n->next=NULL;
    }
    void insertafterhead(Node* n){
        n->next = head->next;
        head->next = n;
        n->next->prev=n;
        n->prev=head;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        int val;
        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            Node* g = m[key];
            val = g->val;
            deletenode(g);
            insertafterhead(g);
            
        }
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end()){
            if(m.size()>=cap){
                m.erase(tail->prev->key);
                deletenode(tail->prev);
                Node* temp = new Node(key,value);
                m[key]=temp;
                insertafterhead(temp);
            }
            else{
                Node* temp = new Node(key,value);
                m[key]=temp;
                insertafterhead(temp);
            }
        }
        else{
            Node* n = m[key];
            n->val=value;
            deletenode(n);
            insertafterhead(n);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */