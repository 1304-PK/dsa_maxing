/*
BFS Approach:

For each node we store its col, row and its value

Since we have stored using a map, the columns are sorted and for each column the rows are sorted and due to multiset, the values
at same row and column are also sorted.

Then we iterate through columns and for each column we iterate through the rows and its multiset and store it in a result variable
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int row = front.second.second;
            int col = front.second.first;
            
            mpp[col][row].insert(front.first->val);
            if (front.first->left) q.push({front.first->left, {col-1, row+1}});
            if (front.first->right) q.push({front.first->right, {col+1, row+1}});
        }

        vector<vector<int>> result;
        for (auto &[col, innerMap] : mpp){
            vector<int> v={};
            for (auto &[row, innerSet] : innerMap){
                for (int a:innerSet) v.push_back(a);
            }
            result.push_back(v);
        }
        return result;
    }
};


/*
DFS Approach:

Using recursion, we visit every node and store its value in tuple, each value has its column, its row and node's value.

sort(nodes.begi(), nodes.end()) sorts the tuple lexicographically, that is columns are sorted and for each column, their rows
are sorted and for each row their values are sorted

and then using a loop the res variable is filled with answer;
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;  // (col, row, val)
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (auto [col, row, val] : nodes) {
            if (col != prevCol) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }

    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& nodes) {
        if (!node) return;
        nodes.emplace_back(col, row, node->val);
        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};