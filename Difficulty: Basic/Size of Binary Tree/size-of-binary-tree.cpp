/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(!root)
        return 0;
        
        return (1+getSize(root->left)+getSize(root->right));
    }
};