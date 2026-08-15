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
    bool isPalindrome(ListNode* head) {
        // Edge cases (empty or single node list)
        if (!head || !head->next) return true;

        // Count number of nodes
        int count = 0;
        ListNode *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        count /= 2;
        ListNode *curr = head, *prev = NULL;

        // Skip number of nodes
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;

        // Reverse the second linked list
        ListNode *front;
        prev = NULL;

        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Prev is pointing to second list
        // Head is pointing to first list
        ListNode *head1 = head, *head2 = prev;

        // Check Palindrome
        while (head1) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};