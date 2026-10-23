/* Binary Tree node Structure 
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    int countLeaves(Node* root) {
        // code here
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return 1;
        
        return(countLeaves(root->left)+countLeaves(root->right));
    }
};