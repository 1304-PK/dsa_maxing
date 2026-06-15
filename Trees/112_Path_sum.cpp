/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void getPathSum(TreeNode *root, int targetSum, bool &hasSum, int currSum){
        if (!root) return;

        currSum+=root->val;
        if ((!root->left && !root->right) && (currSum==targetSum)) hasSum = true;

        getPathSum(root->left, targetSum, hasSum, currSum);
        getPathSum(root->right, targetSum, hasSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool hasSum = false;
        getPathSum(root, targetSum, hasSum, 0);
        return hasSum;
    }
};