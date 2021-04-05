class Node:
    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


class MyCircularDeque:
    def __init__(self, k: int):
        self.head = self.tail = Node(None)
        self.k, self.len = k, 0
        self.head.next, self.tail.prev = self.tail, self.head

    def _del(self, node: Node):
        n = node.next.next
        node.next = n
        n.prev = node

    # 현재 노드와 새로운 노드를 변수로 받는다.
    def _add(self, node: Node, new: Node):
        temp = node.next
        node.next = new
        new.prev, new.next = node, temp
        temp.prev = new

    def insertFront(self, value: int) -> bool:
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.head, Node(value))
        return True

    def insertLast(self, value: int) -> bool:
        if self.len == self.k:
            return False
        self.len += 1
        self._add(self.tail.prev, Node(value))
        return True

    def deleteFront(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.head)
        return True

    def deleteLast(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.tail.prev.prev)
        return True

    def getFront(self) -> int:
        return self.head.next.data if self.len else -1

    def getRear(self) -> int:
        return self.tail.prev.data if self.len else -1

    def isEmpty(self) -> bool:
        return self.len == 0

    def isFull(self) -> bool:
        return self.len == self.k

