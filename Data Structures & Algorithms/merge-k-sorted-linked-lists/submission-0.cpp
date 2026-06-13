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

    bool check(vector<ListNode*>& lists){
         for(int i = 0; i<lists.size(); i++){
         if(lists[i] != NULL) return false;
       }
       return true;
    }

   ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(check(lists)) return NULL;

    ListNode* minnode = NULL;
    int min_index = -1; // Track the index to make advancing the pointer easier
    
    // 1. Find the minimum node
    for(int i = 0; i < lists.size(); i++){
        if(lists[i] == NULL) continue;
        
        // If minnode is NULL, or we found a strictly smaller value, update minnode
        if(minnode == NULL || lists[i]->val < minnode->val) {
            minnode = lists[i];
            min_index = i;
        }
    }
    
    // 2. Advance the pointer of the list we took the node from
    if (min_index != -1) {
        lists[min_index] = lists[min_index]->next;
    }
    
    // 3. Recursive call
    minnode->next = mergeKLists(lists);

    return minnode;
}

       
};
