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

#include <utility>
using namespace std;

#define max(a,b) (a>b?a:b)
#define max3(a,b,c) (max(max(a,b),c))


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return maxDepthAndDiameter(root).second;
    }

    pair<int,int> maxDepthAndDiameter(TreeNode* root) {
        if(root == nullptr)
            return {0,0};
        // return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        pair<int,int> left = maxDepthAndDiameter(root->left);
        pair<int,int> right = maxDepthAndDiameter(root->right);
        return {max(left.first,right.first) + 1, max3(left.second, right.second, left.first + right.first)};
    }
};
