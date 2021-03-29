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


class MyCircularQueue:

    def __init__(self, k: int):
        self.que = [0] * k
        self.MAX_SIZE = k
        self.size = 0
        self.first_idx = 0
        self.last_idx = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.que[self.last_idx] = value
        self.last_idx += 1
        self.last_idx %= self.MAX_SIZE
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.first_idx += 1
        self.first_idx %= self.MAX_SIZE
        self.size -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.que[self.first_idx]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.que[(self.last_idx + self.MAX_SIZE - 1) % self.MAX_SIZE]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.MAX_SIZE


if __name__ == "__main__":
    # Your MyCircularQueue object will be instantiated and called as such:
    obj = MyCircularQueue(3)
    param_1 = obj.enQueue(1)
    param_2 = obj.enQueue(2)
    param_3 = obj.enQueue(3)
    param_4 = obj.enQueue(4)
    param_5 = obj.Rear()
    param_6 = obj.isFull()
    param_7 = obj.deQueue()
    param_8 = obj.enQueue(4)
    param_9 = obj.Rear()

    print(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)

