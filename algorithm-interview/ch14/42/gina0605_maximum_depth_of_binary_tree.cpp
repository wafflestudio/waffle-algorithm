/*
104. Maximum Depth of Binary Tree
8ms, 18.8MB
*/

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
	int ans;

	void dfs(TreeNode *node, int d) {
		if(!node) return;
		ans = max(ans, d);
		dfs(node -> left, d + 1);
		dfs(node -> right, d + 1);
	}

    int maxDepth(TreeNode* root) {
		ans = 0;
		dfs(root, 1);
		return ans;
    }
};
