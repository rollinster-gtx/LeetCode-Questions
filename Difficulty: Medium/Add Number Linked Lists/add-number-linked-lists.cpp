class Solution {
  private:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Helper function to trim any leading zeros
    Node* trimLeadingZeros(Node* head) {
        while (head != NULL && head->data == 0 && head->next != NULL) {
            head = head->next;
        }
        return head;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // Trim leading zeros first
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);

        // Reverse both input lists to add from least significant digit
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry != 0) {
            int sum = carry;

            if (num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        // Reverse the result to restore original order
        Node* result = reverse(dummy->next);
        return trimLeadingZeros(result);
    }
};