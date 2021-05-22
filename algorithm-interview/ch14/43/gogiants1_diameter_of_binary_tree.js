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
 * @return {number}
 */
//root의 left child, right child 따로 path 구해서 더하기
var diameterOfBinaryTree = function(root) {
    let dia = 0
    
    const dfs = root => {
        if(root === null || root === undefined){
            return 0
        }
        let l = dfs(root.left)
        let r = dfs(root.right)
        
        dia = Math.max(l+r, dia) // 현재 루트를 root를 지나지 않는 경로중 max값 저장.

        return Math.max(l,r) + 1 // 상위의 재귀호출에 루트를 지나는 최대 depth 전달
    }
    dfs(root)
    return dia;
};
