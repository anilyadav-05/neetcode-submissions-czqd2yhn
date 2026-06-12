/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;
        bool more = 0;
        while( l1 != NULL || l2 != NULL){
            int x , y;

            if(l1 == NULL) x=0;
            else  x = l1->val;
            if(l2 == NULL) y=0;
            else  y = l2->val;

            int sum = x+y;

            if(more){
                 sum++;
                 more = 0;
            }

            if(sum >= 10){
            sum = sum-10;
            more = 1;
            } 

            ListNode* node = new ListNode(sum);
            tail->next = node;
            tail = tail->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            
        }
        if(more){
          ListNode* node = new ListNode(1);
          tail->next = node;
        }

        tail = temp->next;
        delete temp;
        return tail;
        
    }
};
