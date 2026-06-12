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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevLeft = dummy;

    // reach node just before left
    for(int i = 0; i < left-1; i++)
        prevLeft = prevLeft->next;

    // head2 = leftmost node, tail = rightmost node
    ListNode* head2 = prevLeft->next;
    ListNode* tail = head2;
    for(int i = left; i < right; i++)
        tail = tail->next;

    ListNode* nextRight = tail->next;
    tail->next = nullptr;  // cut

    // reverse head2 to tail
    ListNode* prev = nullptr;
    ListNode* curr = head2;
    while(curr != nullptr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // reconnect — prev is new head, head2 is new tail
    prevLeft->next = prev;
    head2->next = nextRight;

    return dummy->next;
}
};