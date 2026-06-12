/*
Recursive approach

Connect the parent node and connect the children nodes appropriately
and then do same for left branch and right branch
*/

class Solution {
public:

    void connectRight(Node* root){
        if (!root->left) return;

        root->left->next = root->right;
        if (root->next){
            root->right->next = root->next->left;
        }

        connectRight(root->left);
        connectRight(root->right);
    }

    Node* connect(Node* root) {
        if (!root) return root;
        root->next = NULL;
        connectRight(root);
        return root;
    }
};

// --------------------------------------------


/*
BFS Approach

Traverse the tree breadth-wise and then connect each left to right 
with appropriate loops
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        vector<Node*> v;

        q.push(root);
        while(!q.empty()){
            Node *top = q.front();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
            v.push_back(q.front());
            q.pop();
        }
        int i=0, j=0;
        while(j<v.size()-1){
            for (int k=1;k<=pow(2, i)-1;k++){
                v[j]->next = v[j+1];
                j++;
            }
            j++;
            i++;
        }
        return root;
    }
};