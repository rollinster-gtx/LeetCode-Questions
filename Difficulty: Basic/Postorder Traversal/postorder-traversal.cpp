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
  void post(Node*root,vector<int>&ans)
  {
      if(root==NULL)
      return;
      //Left
      post(root->left,ans);
      //Right
      post(root->right,ans);
      //Node
      ans.push_back(root->data);
  }
    vector<int> postOrder(Node* root) {
            vector<int>ans;
            post(root,ans);
            return ans;
    }
};