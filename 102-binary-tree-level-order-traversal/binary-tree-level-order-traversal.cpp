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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root)
            return {};

        vector<vector<int>>ans;
        queue<TreeNode*>que;

        que.push(root);
        while(!que.empty()){

            int N = que.size();
            vector<int>level;

            while(N--){
                TreeNode* rootValue = que.front();
                que.pop();

                level.push_back(rootValue->val);

                if(rootValue->left != NULL){
                    que.push(rootValue->left);
                }
                if(rootValue->right != NULL){
                    que.push(rootValue->right);
                }
            }  
            ans.push_back(level);    
        }
        return ans;
    }       
};