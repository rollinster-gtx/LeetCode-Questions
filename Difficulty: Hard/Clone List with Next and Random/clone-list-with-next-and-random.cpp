/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return nullptr;

        // Step 1: Create and interweave cloned nodes
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->data);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // Step 2: Set random pointers for cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and cloned lists
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;

        while (curr) {
            Node* nextOriginal = curr->next->next;

            // Extract clone
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;

            // Restore original
            curr->next = nextOriginal;
            curr = nextOriginal;
        }

        return dummy->next;
    }
};