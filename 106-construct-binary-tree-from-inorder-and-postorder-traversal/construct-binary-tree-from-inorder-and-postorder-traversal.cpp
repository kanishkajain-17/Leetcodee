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
    //POSTORDER -> ROOT RIGHT LEFT
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx) {

        if(idx < 0 || start > end)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[idx]);
        int i;

        for (i = start; i <= end; i++) {
            if(postorder[idx] == inorder[i])
                break;
        } 

        idx -= 1;
        
        root->right = solve(inorder, postorder, i + 1, end, idx);
        root->left = solve(inorder, postorder, start, i - 1, idx);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n - 1;
        return solve(inorder, postorder, 0, n - 1, idx);
    }
};