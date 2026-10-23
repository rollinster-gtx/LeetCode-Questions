/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        Node*temp;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            ans.push_back(temp->data);
            //left
            if(temp->left)
            q.push(temp->left);
            //right
            if(temp->right)
            q.push(temp->right);
        }
        return ans;
    }
};