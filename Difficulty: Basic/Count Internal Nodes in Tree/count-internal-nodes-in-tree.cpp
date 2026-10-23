/* Binary Tree Node Structure
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // code here
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return 0;
        
        return (1+countNonLeafNodes(root->left)+countNonLeafNodes(root->right));
    }
};