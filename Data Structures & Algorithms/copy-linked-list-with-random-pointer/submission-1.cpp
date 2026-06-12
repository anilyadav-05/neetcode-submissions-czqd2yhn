/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map< Node* , Node* >m;
        if(head == NULL) return NULL;
       Node* temp = head;
        Node* newnode = new Node(temp->val);
        Node* tail = newnode;

   

        m[temp] = newnode;
        temp = temp->next;
        while(temp != NULL){
            Node* node = new Node(temp->val);
            tail->next = node;
            tail = tail->next;
             m[temp] = node; 
             temp = temp->next;
        }
        temp = head;
        tail = newnode;

        while(temp != NULL){
           if(temp->random) m[temp]->random = m[temp->random]; // clone of random
            temp = temp->next;
        }
        return newnode;
    }
};
