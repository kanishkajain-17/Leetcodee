/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    unordered_map<TreeNode*, TreeNode*>parent; //node, parent of that node

    void addParent(TreeNode* root){
        if(!root)
            return;
        if(root->left != NULL)
            parent[root->left] = root;
        addParent(root->left);

        if(root->right != NULL)
            parent[root->right] = root;
        addParent(root->right);
    }

    void allDistance(TreeNode* root, TreeNode* target, int k){
        queue<TreeNode*>que;
        que.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!que.empty()) {
                
                int n = que.size();
                if(k == 0)
                    break;
                
                while(n--) {
                    TreeNode* curr = que.front();
                    que.pop();
                    
                    if(curr->left && !visited.count(curr->left->val)) {
                        que.push(curr->left);
                        visited.insert(curr->left->val);
                    }
                    if(curr->right && !visited.count(curr->right->val)) {
                        que.push(curr->right);
                        visited.insert(curr->right->val);
                    }
                    
                    if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                        que.push(parent[curr]);
                        visited.insert(parent[curr]->val);
                    }
                }
                k--;
            }
            
            while(!que.empty()) {
                TreeNode* temp = que.front();
                que.pop();
                ans.push_back(temp->val);
            }
        }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
            return {};
        addParent(root);
        allDistance(root, target, k);
        return ans;
    }
};