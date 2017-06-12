#include "./stdc++.h"

using namespace std;

struct Node {
	int key;
	int val;
	Node *prev;
	Node *next;
	Node(Node *p, Node *n): prev(p), next(n) {}
	Node(): prev(NULL), next(NULL) {}
};

class LRUCache {
public:
	map<int, Node*> m;
	Node *head;
	Node *tail;
	Node *current;
	int capacity;
    LRUCache(int capacity) {
    	this->capacity = capacity;
    	if (this->capacity == 0) return;
        m.clear();
        Node *curr = NULL;
        head = NULL;
        tail = NULL;
        for (int i = 0; i < capacity; i++) {
        	Node *p = new Node();
        	if (i != 0) {
        		curr->next = p;
        		p->prev = curr;
        	}
        	curr = p;
            if (i == 0) {
                head = curr;
            }
        }
        tail = curr;
        current = NULL;
    }
    
    int get(int key) {
        if (this->capacity == 0) return -1;
        if (m.count(key) <= 0) {
            return -1;
        } else {
            // insert it to current->next and del the key
            Node *t = m[key];
            Node *p = new Node();
            m[key] = p;
            p->key = key;
            p->val = t->val;
            if (current == tail) {
                p->prev = current;
                current->next = p;
                tail = current = p;
            } else {
                current->next->prev = p;
                p->prev = current;
                p->next = current->next;
                current->next = p;
                current = p;
            }
            if (t == head) head = head->next;
            t->next->prev = t->prev;
            if (t->prev) {
                t->prev->next = t->next;
            }
            delete t;
            return m[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (this->capacity == 0) return;
        if (m.count(key) <= 0) {
        	if (current == NULL) {
        		current = head;
        		current->key = key;
	        	current->val = value;
	        	m[key] = current;
	        } else if (current != tail) {
                // cout << "if2" << endl;
	        	current = current->next;
	        	current->key = key;
	    		current->val = value;
	    		m[key] = current;
	        } else {
                // cout << "if3" << endl;
	        	// insert tail
	        	Node *p = new Node();
	        	p->key = key;
	        	p->val = value;
	        	p->prev = tail;
	        	tail->next = p;
	        	tail = p;
	        	current = tail;
	        	// del head
	        	m.erase(head->key);
                // cout << "key: " << head->key << endl;
	        	head->next->prev = NULL;
	        	Node *t = head;
	        	head = t->next;
                m[key] = p;
	        	delete t;
	        }
    	} else {
    		// insert it to current->next and del the key
    		Node *t = m[key];
    		Node *p = new Node();
    		m[key] = p;
    		p->key = key;
    		p->val = value;
        	if (current == tail) {
        		p->prev = current;
        		current->next = p;
        		tail = current = p;
        	} else {
        		current->next->prev = p;
        		p->prev = current;
        		p->next = current->next;
        		current->next = p;
        		current = p;
        	}
        	if (t == head) head = head->next;
        	t->next->prev = t->prev;
        	if (t->prev) {
        		t->prev->next = t->next;
        	}
        	delete t;
    	}
    	// cout << "put: " << endl;
        // cout << (m[key]->val) << endl;
    }
};

int main() {
	LRUCache *cache = new LRUCache( 2 /* capacity */ );
	cache->put(1, 1);
	cache->put(2, 2);
	cout << cache->get(1) << endl;       // returns 1
	cache->put(3, 3);    // evicts key 2
	cout << cache->get(2) << endl;       // returns -1 (not found)
	cache->put(4, 4);    // evicts key 1
	cout << cache->get(1) << endl;       // returns -1 (not found)
	cout << cache->get(3) << endl;       // returns 3
	cout << cache->get(4) << endl;       // returns 4
	return 0;
}