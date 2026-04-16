class Solution {
public:
    void reorderList(ListNode* head) {
        // find the mid point, split into 2 pieces, insert 
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;  // start of next half
        slow->next = nullptr; // cutoff

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // merge
        ListNode* first = head;   // first half first node
        ListNode* second = prev;  // second half first node
        
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};