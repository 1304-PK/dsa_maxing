/*
Iterative approach:

we travel accordingly in BST and add a node whenever a node doesn't exist in that place

TC - O(H), worst - O(N), best - O(LOGN)

SC - O(1)
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root){
            return new TreeNode(val);
        }

        TreeNode *temp = root;
        while(temp){
            if (temp->val<val){
                if (!temp->right){
                    temp->right = new TreeNode(val);
                    return root;
                }
                temp = temp->right;
            }
            else{
                if (!temp->left){
                    temp->left = new TreeNode(val);
                    return root;
                }
                temp = temp->left;
            }
        }
        return root;
    }
};

/*
Recursive approach:

TC - O(H) [worst - O(N), best - O(logN)]
SC - O(H) [worst - O(N), best - O(logN)] - because of stack space due to recursive functions
*/

if(root == NULL) return new TreeNode(val);

if (val > root->val)
    root->right = insertIntoBST(root->right, val);
else
    root->left = insertIntoBST(root->left, val);

return root;