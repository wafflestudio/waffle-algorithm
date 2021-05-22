/**
 * 120ms, 71.9MB
 * time complexity: O(#nodes)
 */

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

#include <iostream>
#include <algorithm>
#include <cmath>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max(int a, int b) { return a > b ? a : b; }

class Solution {
 public:
  int result = 0;
  int dfs(TreeNode* node) {
    if (node == nullptr) return 0;

    int left = dfs(node->left);
    int right = dfs(node->right);

    if (node->left != nullptr && node->left->val == node->val) {
      left += 1;
    } else {
      left = 0;
    }

    if (node->right != nullptr && node->right->val == node->val) {
      right += 1;
    } else {
      right = 0;
    }

    result = max(result, left + right);
    return max(left, right);
  }
  int longestUnivaluePath(TreeNode* root) {
    dfs(root);
    return result;
  }
};