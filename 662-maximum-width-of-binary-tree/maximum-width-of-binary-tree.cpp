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
            return {};
        queue<pair<TreeNode*, ll>>q;
        q.push({root, 0});//node, node number
        ll maxWidth = 0;

        while(!q.empty()){
            int N = q.size();
            ll L = q.front().second;
            ll R = q.back().second;
            maxWidth = max(maxWidth, R - L + 1);

            while(N--){
                TreeNode* node = q.front().first;
                ll num = q.front().second;
                q.pop();

                if(node->left != NULL)
                    q.push({node->left, 2*num+ 1});
                if(node->right != NULL)
                    q.push({node->right, 2*num+ 2});
            }
        }
        return maxWidth;
    }
};