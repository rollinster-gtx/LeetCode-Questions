/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node *slow = head, *fast = head;
        
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
            break;
        };
        
        if(fast==NULL || fast->next==NULL)
        return;
        
        slow = head;
        
        //meet krna
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        };
        
        //slow last node pe
        while(slow->next!=fast)
        {
            slow = slow->next;
        };
        
        slow->next = NULL;
    }
};