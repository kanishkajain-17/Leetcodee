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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> que;
        que.push(root);

        bool leftToRight = true;
        vector<vector<int>> ans;

        while (!que.empty()) {

            int N = que.size();
            vector<int> cur;

            while (N--) {

                TreeNode* node = que.front();
                que.pop();

                cur.push_back(node->val);

                if(node->left != NULL)
                    que.push(node->left);

                if(node->right != NULL)
                    que.push(node->right);
            }

            if(leftToRight == false) {

                reverse(begin(cur), end(cur));
                leftToRight = true;
            }
            else 
                leftToRight = false;
            ans.push_back(cur);
        }
        return ans;
    }
};