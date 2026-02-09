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
    //by iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        //root left right
        if(!root)
            return {};
        vector<int>ans;
        stack<TreeNode*>st;

        st.push(root);
        while(!st.empty()){
            TreeNode* rootValue = st.top();
            st.pop();

            ans.push_back(rootValue->val);

            if(rootValue->right != NULL){
                st.push(rootValue->right);
            }
            
            if(rootValue->left != NULL){
                st.push(rootValue->left);
            }
        }
        return ans;
    }
};