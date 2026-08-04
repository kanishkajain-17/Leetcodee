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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(!root)
            return {};

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> que;

        que.push({root, {0, 0}});

        while (!que.empty()) {

            auto P = que.front();
            que.pop();
            
            TreeNode* node = P.first;
            int x = P.second.first;
            int y = P.second.second;

            mp[x][y].insert(node->val);

            if(node->left != NULL)
                que.push({node->left, {x - 1, y + 1}});

            if(node->right != NULL)
                que.push({node->right, {x + 1, y + 1}});           
        }

        vector<vector<int>> ans;

        for (auto &m : mp) {

            vector<int> col;

            for (auto &p : m.second) {

                for (int val : p.second) {

                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};