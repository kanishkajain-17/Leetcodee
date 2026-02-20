/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void Inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        Inorder(root->left,ans);
        ans.push_back(root->val);
        Inorder(root->right,ans);
    }
    bool check(vector<int> arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end) {
            int sum = arr[start] + arr[end];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                end--;
            } else {
                start++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        Inorder(root,arr);
        return check(arr, k);
    }
};