class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp->next != NULL && temp->next->next != NULL) {

            ListNode* first = temp->next;
            ListNode* second = temp->next->next;

            first->next = second->next;
            second->next = first;
            temp->next = second;

            temp = first;
        }

        return dummy->next;
    }
};