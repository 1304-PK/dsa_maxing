/*
My approach:

The function getLeftSum actually returns whether the node is leaf node or not and then if a node's left child is a leaf node and is actually not null then we add it to the sum
*/
class Solution {
public:

    bool getLeftSum(TreeNode *root, int &sum){
        if (!root) return true;

        if (!root->left && !root->right) return true;
        bool leftChild = getLeftSum(root->left, sum);
        bool rightChild = getLeftSum(root->right, sum);

        if (leftChild && root->left) sum+=root->left->val;

        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getLeftSum(root, sum);
        return sum;
    }
};


/*
Another approach:

traverses the tree and for every node returns the sum of leftLeafSum of left + right

and it returns sum of that node only when its a left child
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) { // Leaf node
            return isLeft ? node->val : 0;
        }
        int leftSum = dfs(node->left, true);    // Traverse left child
        int rightSum = dfs(node->right, false); // Traverse right child
        return leftSum + rightSum;
    }
};