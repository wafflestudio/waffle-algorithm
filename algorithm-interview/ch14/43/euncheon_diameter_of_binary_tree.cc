// 12ms, 20.2MB
// O(#nodes)

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
    int max_diameter = 0;
public:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left_depth=0, right_depth = 0;
        
        if (node->left) left_depth = dfs(node->left) + 1;
        if (node->right) right_depth = dfs(node->right) + 1;
        max_diameter = max(max_diameter, left_depth + right_depth);
        
        return max(left_depth, right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }
};