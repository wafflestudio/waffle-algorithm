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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left_depth = 0, right_depth = 0;
        int max_child_depth = 0;
        
        if (root->left) left_depth = maxDepth(root->left);
        if (root->right) right_depth = maxDepth(root->right);
        
        max_child_depth = max(left_depth, right_depth);
        
        return max_child_depth + 1;
    }
};