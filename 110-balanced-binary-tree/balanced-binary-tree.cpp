
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
