/*
Optimal approach using only one queue

The approach here is we are storing elements in queue from left to right as usual but when 
updating the v array we fill from left to right if leftToRight is true else we fill from right to left

TC - O(N) cause traversal
SC - O(N) cause complete binary tree last row has n/2 nodes and the res vector will have N nodes
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;
        queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);
        bool leftToRight = true;
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> v(size);

            for (int i=0;i<size;i++){
                int index = (leftToRight) ? i : (size-1-i);
                TreeNode *front = nodeQueue.front();
                nodeQueue.pop();

                v[index] = front->val;
                if (front->left) nodeQueue.push(front->left);
                if (front->right) nodeQueue.push(front->right);

            }
            leftToRight = !leftToRight;
            res.push_back(v);
        }
        return res;
    }
};


/*
Approach using two stacks:

one for left to right and other for right to left

TC - O(N) cause its a traversal
SC - O(N) because in complete binary tree, the last row has about n/2 nodes
*/ 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;

        stack<TreeNode*> ltor;
        stack<TreeNode*> rtol;
    

        ltor.push(root);
        bool fromLeft = false;
        while(!(ltor.empty() && rtol.empty())){
            vector<int> v;
            if (fromLeft){
                while(!rtol.empty()){
                    TreeNode *top = rtol.top();
                    if (top->right) ltor.push(top->right);
                    if (top->left)ltor.push(top->left);
                    v.push_back(rtol.top()->val);
                    rtol.pop();
                }
                res.push_back(v);
                v = {};
                fromLeft = false;
            }
            else{
                while(!ltor.empty()){
                    TreeNode* top = ltor.top();
                    if (top->left) rtol.push(top->left);
                    if (top->right) rtol.push(top->right);
                    v.push_back(ltor.top()->val);
                    ltor.pop();
                }
                res.push_back(v);
                v = {};
                fromLeft = true;
            }
        }
        return res;
    }
};