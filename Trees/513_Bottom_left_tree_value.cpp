/*
Optimal Approach:

For every level we pass currDepth and maxDepth and if currDepth for any node exceeds maxDepth(strictly greater) only then we update the value variable

Implementing strictly greater is how we ensure leftmost data for nodes at same level

TC - O(N)
SC - O(H) - worst case O(N) and best case O(logN)
*/


class Solution {
public:

    void getLeftValue(TreeNode *root, int &val, int &maxDepth, int currDepth){
        if (!root) return;

        getLeftValue(root->left, val, maxDepth, currDepth+1);
        getLeftValue(root->right, val, maxDepth, currDepth+1);

        if (currDepth>maxDepth){
            val = root->val;
            maxDepth = currDepth; 
        }

        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;

        int val = root->val;
        int maxDepth = 0;
        getLeftValue(root, val, maxDepth, 0);
        return val;
    }
};