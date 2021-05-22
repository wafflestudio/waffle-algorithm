/*
543. Diameter of Binary Tree
12ms, 20.8MB
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

typedef pair<int, int> pii;

#define fi first
#define se second

class Solution {
public:
	pii dfs(TreeNode* root) {
		if(!root) return pii(0, 0);
		pii l = dfs(root->left);
		pii r = dfs(root->right);
		return pii(max(l.se + r.se + 1, max(l.fi, r.fi)), max(l.se, r.se) + 1);
	}

    int diameterOfBinaryTree(TreeNode* root) {
		return dfs(root).fi - 1;
    }
};
