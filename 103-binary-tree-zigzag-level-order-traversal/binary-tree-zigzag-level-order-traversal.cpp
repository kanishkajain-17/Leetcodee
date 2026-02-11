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
        queue<TreeNode*>que;
        vector<vector<int>>ans;
        que.push(root);
        bool leftToRight = true;

        while(!que.empty()){
            int N = que.size();
            vector<int>level(N);

            for(int i = 0; i < N; i++){
                TreeNode* node = que.front();
                que.pop();

                int idx = (leftToRight) ? i : (N - 1 - i);
                level[idx] = node->val;

                if(node->left != NULL)
                    que.push(node->left);
                if(node->right != NULL)
                    que.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
    return ans;        
    }
};