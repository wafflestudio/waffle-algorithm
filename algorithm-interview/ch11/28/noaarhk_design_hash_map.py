import collections


class MyHashMap:
    def __init__(self):
        self.size = 1000
        self.table = collections.defaultdict(ListNode)

    def put(self, key: int, value: int) -> None:
        index = key % self.size
        p = self.table[index]
        # 해당 인덱스에 노드가 존재하는경우 -> 해시충돌이 발생한 경우
        while p:

            # 해당 인덱스에 존재하는 키가 삽입하려는 키와 같을 때 (원래 있는 키의 값을 업데이트하려 할때 ) 그 키의 값을 넣어주는 값으로 업데이트한다.
            if p.key == key:
                p.value = value
                return

            # 이 조건을 설정하지 않는다면 다음 진행시 에러 발생 ? 의문 - defaultdict에서 이런경우가 발생하나? ㅇㅇ next는 defaultdict로 정의한 적 없음
            if not p.next:
                break

            p = p.next

    def get(self, key: int) -> int:
        index = key % self.size
        # 해당하는 인덱스의 값이 없을 떄
        if not self.table[index].value:
            return -1

        p = self.table[index]

        # 하나 이상의 노드가 존재할 때 ? 의문 - 해당 인덱스에 노드가 두개인 경우 ? 일치하는 키를 찾아서 값을 리턴한다.
        while p:
            if p.key == key:
                return p.value
            p = p.next
        return -1

    # 키에 해당하는 키 , 값을 테이블에서 삭제한다.
    def remove(self, key: int) -> None:
        index = key % self.size
        p = self.table[index]
        # case of the first node is the target
        if p.key == key:
            # self.table[index] 에 Nond을 할당하면, 추가, 조회시 에러 발생
            self.table[index] = ListNode() if not p.next else p.next
            return

        prev = p
        # case of the first node is not the target - key probing
        while p:
            if p.key == key:
                prev.next = p.next
                return
            prev, p = p, p.next







class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None


if __name__ == '__main__':
    myhash = MyHashMap()
    myhash.put(10, 100)
