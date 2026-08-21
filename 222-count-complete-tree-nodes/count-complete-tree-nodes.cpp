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
    int findLeft(TreeNode* root) {
        TreeNode* temp = root;
        int lh = 0;

        while (temp != NULL) {
            lh += 1;
            temp = temp->left;
        }
        return lh;
    }
    int findRight(TreeNode* root) {
        TreeNode* temp = root;
        int rh = 0;

        while (temp != NULL) {
            rh += 1;
            temp = temp->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh)
            return pow(2, lh) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};