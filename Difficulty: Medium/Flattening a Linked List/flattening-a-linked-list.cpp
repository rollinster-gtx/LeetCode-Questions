/*
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  private:
    // Helper function to merge two sorted bottom lists in O(1) space
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result = NULL;
        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        result->next = NULL; // bottom list maintain rakhna hai, next null
        return result;
    }

    // Iterative merge (True O(1) Aux Space without recursion stack)
    Node* mergeIterative(Node* a, Node* b) {
        Node dummy(0);
        Node* tail = &dummy;

        while (a != NULL && b != NULL) {
            if (a->data <= b->data) {
                tail->bottom = a;
                a = a->bottom;
            } else {
                tail->bottom = b;
                b = b->bottom;
            }
            tail = tail->bottom;
            tail->next = NULL;
        }

        if (a != NULL) tail->bottom = a;
        else tail->bottom = b;

        return dummy.bottom;
    }

  public:
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Mid point find karo (Merge Sort ki tarah list ko do parts me split karne ke liye)
        Node* slow = root;
        Node* fast = root->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = NULL; // List split ki

        // Left aur Right halves ko divide and conquer se sort/flatten karo
        Node* left = flatten(root);
        Node* right = flatten(mid);

        // Dono parts ko merge karo
        return mergeIterative(left, right);
    }
};