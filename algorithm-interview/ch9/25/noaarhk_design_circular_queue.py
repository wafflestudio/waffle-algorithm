# 원형 큐 디자인
class MyCircularQueue:
    def __init__(self, size: int):
        # the size of the queue
        self.size = size
        # two pointer ( front, rear )
        self.front = 0
        self.rear = 0
        # set the circular queue
        self.q = [None] * size

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        else:
            self.rear = (self.rear + 1) % self.size
            self.q[self.rear] = value
            return True

    def deQueue(self):
        if self.isEmpty():
            return False
        else:
            self.front = (self.front + 1) % self.size
            temp = self.q[self.front]
            self.q[self.front] = None
            return temp

    def isFull(self) -> bool:
        return (self.rear + 1) % self.size == self.front

    def isEmpty(self) -> bool:
        return self.rear == self.front


if __name__ == '__main__':
    mcq = MyCircularQueue(5)
    mcq.enQueue(10)
    mcq.enQueue(20)
    print(mcq.q)
    print(mcq.q[mcq.front], mcq.q[mcq.rear])
    print(mcq.deQueue())
    print(mcq.q)
