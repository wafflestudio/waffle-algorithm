#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
232. Implement Queue using Stacks
"""

from collections import deque


class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.st = deque()
        self.tmp = deque()

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        while self.st:
            self.tmp.appendleft(self.st.popleft())
        self.st.appendleft(x)
        while self.tmp:
            self.st.appendleft(self.tmp.popleft())

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.st:
            return self.st.popleft()

    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.st:
            return self.st[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.st


if __name__ == "__main__":
    # Your MyQueue object will be instantiated and called as such:
    obj = MyQueue()
    obj.push(1)
    param_2 = obj.pop()
    param_3 = obj.peek()
    param_4 = obj.empty()

    print(param_2, param_3, param_4)

