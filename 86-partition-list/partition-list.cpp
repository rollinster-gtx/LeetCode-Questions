class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* p = small;
        ListNode* q = large;

        while(head != NULL)
        {
            if(head->val < x)
            {
                p->next = head;
                p = p->next;
            }
            else
            {
                q->next = head;
                q = q->next;
            }

            head = head->next;
        }

        q->next = NULL;
        p->next = large->next;

        return small->next;
    }
};
