/*
687. Longest Univalue Path
112ms, 72MB
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
	pii dfs(TreeNode* root, int v) {
		if(!root || root->val != v) return pii(0, 0);
		pii l = dfs(root->left, v);
		pii r = dfs(root->right, v);
		return pii(max(l.se + r.se + 1, max(l.fi, r.fi)), max(l.se, r.se) + 1);
	}

	int f(TreeNode* root, int pv) {
		if(!root) return 0;
		int ans = max(f(root->left, root->val), f(root->right, root->val));
		if(root->val != pv) ans = max(ans, dfs(root, root->val).fi - 1);
		return ans;
	}

    int longestUnivaluePath(TreeNode* root) {
        return f(root, -1);
    }
};
