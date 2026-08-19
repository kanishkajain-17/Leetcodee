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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        ll ans = 0;

        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});

        while (!que.empty()) {

            int N = que.size();

            ll L = que.front().second;
            ll R = que.back().second;
  
            ans = max(ans, R - L + 1);

            while (N--) {
                TreeNode* node = que.front().first;
                ll idx = que.front().second;

                que.pop();

                if(node->left)
                    que.push({node->left, 2 * idx + 1});
                if(node->right)
                    que.push({node->right, 2 * idx + 2});
            }
        }
        return ans;
    }
};