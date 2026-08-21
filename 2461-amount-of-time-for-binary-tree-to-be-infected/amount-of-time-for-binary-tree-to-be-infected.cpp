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
    void makeGraph( unordered_map<int, vector<int>> &adj, int parent, TreeNode* cur) {

        if(cur == NULL)
            return;
        
        if(parent != -1)
            adj[cur->val].push_back(parent);

        if(cur->left != NULL)
            adj[cur->val].push_back(cur->left->val);

        if(cur->right != NULL)
            adj[cur->val].push_back(cur->right->val);

        
        makeGraph(adj, cur->val, cur->left);
        makeGraph(adj, cur->val, cur->right);

    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        queue<int> que;
        que.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int cur = que.front();
            que.pop();

            for (int &ngbr : adj[cur]) {

                if(visited.count(ngbr) == 0) {
                    visited.insert(ngbr);
                    que.push(ngbr);
                }
            }
           
        }  
         minutes += 1;               
    }
        return minutes - 1;
    }
};