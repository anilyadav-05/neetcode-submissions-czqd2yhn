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
void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return;

    // Step 1: Find middle
    ListNode* slow = head;
    ListNode* fast = head->next; // fast starts at head->next

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHalf = slow->next;
    slow->next = nullptr;        // cut — no need for prev pointer at all

    // Step 2: Reverse second half
    ListNode* curr = secondHalf;
    ListNode* revPrev = nullptr;
    while(curr != nullptr) {
        ListNode* nxt = curr->next;
        curr->next = revPrev;
        revPrev = curr;
        curr = nxt;
    }

    // Step 3: Merge
    ListNode* first = head;
    ListNode* second = revPrev;
    while(second != nullptr) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
};
