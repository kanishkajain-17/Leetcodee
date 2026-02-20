class NodeValue{
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0;

    NodeValue helper(TreeNode* root){
        // empty tree → valid BST with sum = 0
        if(!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // check BST condition
        if(left.maxNode < root->val && root->val < right.minNode){
            int currSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // not a BST → return invalid range
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};