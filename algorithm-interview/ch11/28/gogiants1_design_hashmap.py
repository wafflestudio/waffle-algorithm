import collections
'''
706번 해시테이블 구현. 개별 체이닝 방식 구현. 연결 리스트 활용.
'''


class ListNode:
        def __init__(self, key= None, value= None):
            self.key = key
            self.value = value
            self.next = None
            
class MyHashMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 1000
        self.table = collections.defaultdict(ListNode) # default dict 로 선언했기 때문에 비어있는 키의 경우 값을 자동으로 디폴트 값으로 초기화.

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        index = key % self.size     # 해시 함수를 나머지 연산으로.
        if self.table[index].value is None:
            self.table[index] = ListNode(key , value)
            return
        
        p = self.table[index]
        while p: # 링크드리스트 마지막 노드까지 탐색. 
            if p.key == key:
                p.value = value
                return
            if p.next is None:
                break
            p = p.next
        p.next = ListNode(key, value) 
        
    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        index = key % self.size
        if self.table[index].value is None:
            return -1

        p = self.table[index]
        while p: # 충돌 발생 시 원하는 키 값을 찾을 때까지 탐색. 
            if p.key == key:
                return p.value
            p = p.next
        return -1

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        index = key % self.size
        if self.table[index].value is None:
            return
        p = self.table[index]
        if p.key == key:
            self.table[index] = ListNode() if p.next is None else p.next
            return
        prev = p
        while p:
            if p.key == key:
                prev.next = p.next
                return
            prev, p = p , p.next

if __name__ == "__main__":
    obj = MyHashMap()
    obj.put(1,2)
    param_2 = obj.get(1)
    print(param_2)
    obj.remove(1)
    param_3 = obj.get(1)
    print(param_3)    
