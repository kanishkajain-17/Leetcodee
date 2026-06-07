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
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = ans.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int sum = ans[l] + ans[r];
            if(sum == k)
                return true;
            else if(sum > k)
                r -= 1;
            else
                l += 1;
        }
        return false;
    }
};