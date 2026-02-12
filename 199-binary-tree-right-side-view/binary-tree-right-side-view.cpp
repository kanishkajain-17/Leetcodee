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
    void preOrder(TreeNode* root, int level, vector<int>& ans){
        if(!root)
            return;
        if(ans.size() < level)
            ans.push_back(root->val);
        preOrder(root->right, level + 1, ans);
        preOrder(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        // if(!root)
        //     return {};
        // vector<int>ans;
        // queue<pair<TreeNode*,pair<int, int>>>q; //node, level
        // q.push({root, {0, 0}});
        // map<int, int>mp; //vertical axis coordinate, node value
        
        // while(!q.empty()){
        //     auto it = q.front();
        //     q.pop();
            
        //     TreeNode* node = it.first;
        //     int vertical = it.second.first;
        //     int level = it.second.second;
            
        //     if(mp.find(level) == mp.end())
        //         mp[level] = node->val;
                      
        //     if(node->right != NULL)
        //         q.push({node->right, {vertical + 1, level + 1}});
        //     if(node->left != NULL)
        //         q.push({node->left, {vertical - 1, level + 1}});
        // }
        // for(auto it : mp)
        //     ans.push_back(it.second);
        // return ans;


        //USING BFS---------->>

        // if(!root)
        //     return {};
        // vector<int>ans;
        // queue<TreeNode*>que;
        
        // que.push(root);
        // while(!que.empty()){
        //     TreeNode * node = NULL;
        //     int N = que.size();
            
        //     while(N--){
        //         node = que.front();
        //         que.pop();
                
        //         if(node->left != NULL)
        //             que.push(node->left);

        //         if(node->right != NULL)
        //             que.push(node->right);
        //     }
        //     ans.push_back(node->val);
        // }
        // return ans;



        //USING DFS----------->>
        if(!root)
            return {};
        vector<int>ans;
        preOrder(root, 1, ans);
        return ans;
    }
};