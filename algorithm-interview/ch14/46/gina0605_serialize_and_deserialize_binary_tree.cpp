/*
297. Serialize and Deserialize Binary Tree
36ms, 39MB
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	int idx;
	string s;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "X ";
		return to_string((root->val) + 1000) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
		s = data;
		return f();
    }

	TreeNode* f() {
		if(s[idx] == 'X') {
			idx += 2;
			return 0;
		}
		int n = 0;
		for(; s[idx] != ' '; idx++) n = n * 10 + s[idx] - '0';
		idx++;
		TreeNode* t = new TreeNode(n - 1000);
		t->left = f();
		t->right = f();
		return t;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
