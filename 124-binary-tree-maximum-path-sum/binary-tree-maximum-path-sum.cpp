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
    int solve(TreeNode* root, int & result){
        if(!root)
            return 0;
        int leftH = max(0, solve(root->left, result));
        int rightH = max(0, solve(root->right, result));

        result = max(result, leftH + rightH + root->val);
        return max(leftH, rightH) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};