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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int>ans;
        TreeNode* cur = root;

        while(cur != NULL){
           
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                
                TreeNode* leftChild = cur->left;
                while(leftChild->right != NULL && leftChild->right != cur)
                    leftChild = leftChild->right;

                if(leftChild->right == NULL){
                    leftChild->right = cur;
                    cur = cur->left;
                }
                else{
                    leftChild->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};