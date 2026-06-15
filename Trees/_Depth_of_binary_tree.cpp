/*
Recursive Approach:

For every node calculate its left height and right recursively and calculate their max and add 1 to get the height of that node(node wise depth and not edge wise)

on empty node we return 0(node wise depth calculation)

TC - O(N)
SC - O(N) - Skew tree
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

/*
Iterative approach: (Queue)

For every node we add and then remove the latest node added and add its left and right child and with every step we increase a variable depth

It also calculates weird tree shape depth as only those nodes who has more child will lead to increment in depth whereas leaf nodes will contribute nothing to depth and all nodes at a single level will only increment depth by 1 (because of for loop of size)

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};