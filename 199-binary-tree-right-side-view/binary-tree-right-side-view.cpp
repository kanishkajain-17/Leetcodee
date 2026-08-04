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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
            
        queue<TreeNode*> que;
        que.push(root);

        vector<int> ans;

        while (!que.empty()) {

            TreeNode* node = NULL;
            int N = que.size();

            while (N--) {

                node = que.front();
                que.pop();

                if(node->left != NULL)
                    que.push(node->left);

                if(node->right != NULL)
                    que.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};