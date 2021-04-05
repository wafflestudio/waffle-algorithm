class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        self.peek()
        return self.output.pop()

    def peek(self) -> int:
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        return self.output[-1]

    def empty(self) -> bool:
        return self.input == [] and self.output == []


if __name__ == '__main__':
    obj = MyQueue()
    obj.push(1)
    obj.push(2)
    obj.push(3)
    obj.push(4)
    param_2 = obj.pop()
    print(param_2)
    obj.push(5)
    obj.push(6)
    obj.pop()
    param_3 = obj.pop()
    param_4 = obj.pop()
    param_5 = obj.pop()
    param_6 = obj.pop()
    print(param_3, param_4, param_5, param_6)
