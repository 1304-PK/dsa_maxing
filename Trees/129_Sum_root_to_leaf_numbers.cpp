/*
Optimal Approach:

Here whenever you encounter a node, you add its value in a pathSum variable
and you do this for every individual pathSums until you encounter a leaf node

On encountering a leaf node you add to the sum the pathSum
and return the total sum calculated

TC - O(N) DFS
SC - O(N) Height of the tree

*/


class Solution {
public:

    void getRootLeafSum(TreeNode *root, int &sum, int pathSum){
        if (!root) return;

        pathSum = pathSum*10 + root->val;
        if (!root->left && !root->right) sum+=pathSum;

        getRootLeafSum(root->left, sum, pathSum);
        getRootLeafSum(root->right, sum, pathSum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        getRootLeafSum(root, sum, 0);
        return sum;
    }
};