/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */


/*
Time Submitted      Status      Runtime     Memory      Language
05/29/2021 00:13	Accepted	72 ms       39 MB	    javascript
 */

 var invertTree = function(root) {
    function changeLeftRight(node){
        if (node === undefined || node == null ){
            return node
        }
        
        if (node.right || node.left ){
            changeLeftRight(node.right)
            changeLeftRight(node.left)
            tmp = node.right
            node.right = node.left
            node.left = tmp
            return node
        }
    }
    
    changeLeftRight(root)
    return root
};