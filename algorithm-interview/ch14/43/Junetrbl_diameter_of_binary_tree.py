class Solution:
    def __init__(self):
        self.max_length = 0

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        
        def getDiameter(self, root):
            left_diameter = 0
            right_diameter = 0

            if root.left:
                left_diameter= getDiameter(self, root.left) + 1
            if root.right:
                right_diameter = getDiameter(self, root.right) + 1
            
            self.max_length = max(self.max_length, left_diameter + right_diameter)
            return max(left_diameter, right_diameter)
        
        diameter = getDiameter(self, root)
        return self.max_length
