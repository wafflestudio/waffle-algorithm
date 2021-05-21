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

#include <tuple>
using namespace std;

#define max(a,b) (a>b?a:b)
#define max3(a,b,c) (max(max(a,b),c))


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return get<2>(maxDepth(root));
    }

    // current_val, current_path, longest_val, longest_path
    tuple<int,int,int> maxDepth(TreeNode* root) {
        int current_val=root->val;
        int current_path;
        int longest_path;
        if(root == nullptr)
            return {-10000,0,0};
        current_val = root->val;
        tuple<int,int,int> left = maxDepth(root->left);
        tuple<int,int,int> right = maxDepth(root->right);
        int left_val = get<0>(left);
        int right_val = get<0>(right);
        int left_path = get<1>(left);
        int right_path = get<1>(right);
        if(current_val == left_val && current_val == right_val){
            current_path = max(left_path,right_path) + 1;
            longest_path = max3(left_path+right_path+2,get<2>(left),get<2>(right));
        }
        else if(current_val == left_val){
            current_path = left_path + 1;
            longest_path = max3(left_path+1,get<2>(left),get<2>(right));
        }
        else if(current_val == right_val){
            current_path = right_path + 1;
            longest_path = max3(right_path+1,get<2>(left),get<2>(right));
        }
        else{
            current_path = 0;
            longest_path = max(get<2>(left),get<2>(right));
        }
        return {root->val,current_path,longest_path};
    }
};
