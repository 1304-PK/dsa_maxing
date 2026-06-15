/*
Optimal Approach:

same code as calculating height using recursion
*/

class Solution {
public:

    int getDepth(TreeNode *root){
        if (!root) return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        return 1 + max(left, right);
    }

    int maxDepth(TreeNode* root) {
        int depth = getDepth(root);
        return depth;
    }
};