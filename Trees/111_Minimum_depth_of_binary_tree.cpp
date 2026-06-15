/*
Optimal Approach:

In the height code for binary tree we just replace max with min

But first we check that both l and r are not 0, if even one of them is zero we return the one which is not zero.
*/

class Solution {
public:

    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        return 1 + ((l && r) ? min(l, r) : max(l, r));   
    }
};