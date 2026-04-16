class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        std::vector<ListNode*> vec;
        //ListNode* curr = head;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }

        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i >= j) break;
            vec[j]->next = vec[i];
            j--;
        }

        vec[i]->next = nullptr;
    }
};