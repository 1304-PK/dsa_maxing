/*
Ceil in binary tree means an element equal to given value of an immediate greater value

Approach:

Whenver we find a greater element we update the variable ceil and move to the left in the tree
and we update it because the next greater element than target would automatically be smaller than the previous ceil because we moved left in the binary tree.
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        if (!root) return 0;
        
        int ceil = -1;
        Node *temp = root;
        while(temp){
            if (temp->data==x) return x;
            else{
                if (temp->data>x){
                    ceil = temp->data;
                    temp = temp->left;
                }
                else temp = temp->right;
            }
        }
        return ceil;
    }
};
