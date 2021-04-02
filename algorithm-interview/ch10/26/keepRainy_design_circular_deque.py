#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
641. Design Circular Deque
"""


class MyCircularDeque:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.lst = [0] * k
        self.MAX_SIZE = k
        self.first_idx = 0
        self.last_idx = 0
        self.size = 0

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        self.first_idx -= 1
        if self.first_idx == -1:
            self.first_idx += self.MAX_SIZE
        self.lst[self.first_idx] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        self.lst[self.last_idx] = value
        self.size += 1
        self.last_idx += 1
        if self.last_idx == self.MAX_SIZE:
            self.last_idx -= self.MAX_SIZE
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.first_idx += 1
        self.size -= 1
        if self.first_idx == self.MAX_SIZE:
            self.first_idx -= self.MAX_SIZE
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.last_idx -= 1
        self.size -= 1
        if self.last_idx == -1:
            self.last_idx += self.MAX_SIZE
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.isEmpty():
            return -1
        return self.lst[self.first_idx]

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.isEmpty():
            return -1
        return self.lst[(self.last_idx + self.MAX_SIZE - 1) % self.MAX_SIZE]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self.size == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.size == self.MAX_SIZE


if __name__ == "__main__":
    # Your MyCircularDeque object will be instantiated and called as such:
    obj = MyCircularDeque(3)
    param_1 = obj.insertLast(1)
    param_2 = obj.insertLast(2)
    param_3 = obj.insertFront(3)
    param_4 = obj.insertFront(4)
    param_5 = obj.getRear()
    param_6 = obj.isFull()
    param_7 = obj.deleteLast()
    param_8 = obj.insertFront(4)
    param_9 = obj.getFront()

    print(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)

