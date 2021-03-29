#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
739. Daily Temperatures
"""


class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.que = []
        self.tmp = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.tmp.append(x)
        while self.que:
            self.tmp.append(self.que.pop(0))
        self.que, self.tmp = self.tmp, self.que

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.que:
            return self.que.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        if self.que:
            return self.que[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.que


if __name__ == "__main__":
    # Your MyStack object will be instantiated and called as such:
    obj = MyStack()
    obj.push(1)
    obj.push(2)
    param_2 = obj.top()
    param_3 = obj.pop()
    param_4 = obj.empty()

    print(param_2, param_3, param_4)

