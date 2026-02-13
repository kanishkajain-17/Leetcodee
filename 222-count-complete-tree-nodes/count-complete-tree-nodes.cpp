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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int count = 1;

        while(!q.empty()){
            
            int N = q.size();

            while(N--){
                TreeNode * node = q.front().first;
                int i = q.front().second;
                q.pop();

                if(node->left != NULL){
                    count++;
                    q.push({node->left, 2 * i + 1});
                }
                    
                if(node->right != NULL){
                    count++;
                    q.push({node->right, 2 * i + 2});
                }
                    
            }
            
        }
        return count;
    }
};