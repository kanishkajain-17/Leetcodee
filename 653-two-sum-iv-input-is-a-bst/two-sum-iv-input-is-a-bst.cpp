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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    void pushLeft(TreeNode* root) {
        while (root) {
            asc.push(root);
            root = root->left;
        }
    }
    int nextSmallest() {
        TreeNode* temp = asc.top();
        asc.pop();
        pushLeft(temp->right);
        return temp->val;
    }
    void pushRight(TreeNode* root) {
        while (root) {
            desc.push(root);
            root = root->right;
        }
    }
    int nextLargest() {
        TreeNode* temp = desc.top();
        desc.pop();
        pushRight(temp->left);
        return temp->val;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        pushLeft(root);
        pushRight(root);

        int left = nextSmallest();
        int right =  nextLargest();
        while (left < right) {
            int sum = left + right;
            if(sum == k)    
                return true;
            else if(sum > k)
                right = nextLargest();
            else
                left = nextSmallest();
        }
        return false;
    }
};