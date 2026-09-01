class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;

        Node *prev;
        Node *next;

        Node(int k, int v){
            key=k;
            val=v;
        }
    };

    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> m;

    void addNode(Node *nNode){
        Node *temp=head->next;

        nNode->next=temp;
        nNode->prev=head;

        head->next=nNode;
        temp->prev=nNode;
    }

    void delNode(Node *dNode){
        Node *p=dNode->prev;
        Node *n=dNode->next;

        p->next=n;
        n->prev=p;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->next=head;
    }
    
    int get(int key) {
        if(m.count(key)>0){
            Node *curr=m[key];
            int ans=curr->val;

            delNode(curr);
            addNode(curr);

            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)>0){
            Node* curr=m[key];

            m.erase(key);
            delNode(curr);
        }

        if(m.size()==cap){
            m.erase(tail->prev->key);
            delNode(tail->prev);

        }

        addNode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */