#
# LeetCode
# ver.Python
#
# Created by GGlifer
#
# Open Source

"""
706. Design HashMap
"""


class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.hm = dict()

    def put(self, key: int, value: int) -> None:
        """
        value will always be non-negative.
        """
        self.hm[key] = value

    def get(self, key: int) -> int:
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """
        return self.hm.get(key, -1)

    def remove(self, key: int) -> None:
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """
        try:
            self.hm.pop(key)
        except KeyError:
            pass


if __name__ == "__main__":
    myHashMap = MyHashMap()
    print(myHashMap.put(1, 1))
    print(myHashMap.put(2, 2))
    print(myHashMap.get(1))
    print(myHashMap.get(3))
    print(myHashMap.put(2, 1))
    print(myHashMap.get(2))
    print(myHashMap.remove(2))
    print(myHashMap.get(2))

