/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */

/* 
Time Submitted      Status      Runtime Memory  Language
05/29/2021 01:11	Accepted	108 ms	46.3 MB	javascript

*/

// 트리에서 겹치는 부분(구조상에서.) 있으면 노드의 밸류를 더해서 새로운 노드를 만들어서 합친다
let mergeTrees = function(t1, t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    
    t1.val += t2.val;
    
    t1.left = mergeTrees(t1.left, t2.left);
    t1.right = mergeTrees(t1.right, t2.right);
    
    return t1;
    
};