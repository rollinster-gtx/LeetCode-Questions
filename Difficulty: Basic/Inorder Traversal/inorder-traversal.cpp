/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  void in(Node*root,vector<int>&ans)
  {
      if(root==NULL)
      return;
      //Left
      in(root->left,ans);
      //Node
      ans.push_back(root->data);
      //Right
      in(root->right,ans);
  }
    vector<int> inOrder(Node* root) {
            vector<int>ans;
            in(root,ans);
            return ans;
    }
};