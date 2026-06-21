/*
Floor in binary search tree is a value equal to X or an immediate smaller value than X

Approach:

Whenever we find an element smaller than the target we save it in floor and move to the right and we keep updating because the next
smaller we would find would automatically be greater than the previous floor variable value because we moved right in the binary tree.

*/

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    if (!root) return floor;

    TreeNode<int> *temp = root;
    while(temp){
        if (temp->val==X) return X;
        else if (temp->val>X) temp = temp->left;
        else{
            floor = temp->val;
            temp = temp->right;
        } 
    }
    return floor;
}