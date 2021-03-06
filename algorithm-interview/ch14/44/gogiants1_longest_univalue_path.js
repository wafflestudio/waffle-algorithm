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
 var longestUnivaluePath = function(root) {
    let max = 0
    
    const dfs = root => {
        if(root === null || root === undefined){
            return 0
        }
        let l = dfs(root.left)
        let r = dfs(root.right)
        
        if (root.right && root.right.val === root.val){
            r++;
        }
        else{
            r=0;
        }
        if (root.left && root.left.val === root.val){
            l++;
        } else{
            l = 0;
        }
        max = Math.max(l+r, max) // 현재 루트를 root를 지나지 않는 경로중 max값 저장.

        return Math.max(l,r)  // 상위의 재귀호출에 루트를 지나는 최대 경로길이 전달
    }
    dfs(root)
    return max;
};