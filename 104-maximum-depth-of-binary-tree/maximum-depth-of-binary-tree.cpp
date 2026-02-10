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
    int count(TreeNode* root){
        if(!root)
            return 0;
        int leftH = count(root->left);
        int rightH = count(root->right);

        return max(leftH, rightH) + 1;

    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return NULL;
        return count(root);
    }
};