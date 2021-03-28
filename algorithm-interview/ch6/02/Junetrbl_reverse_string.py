from typing import List


class Solution:
    def reverse_string(self, s: List[str]) -> None:
        """
        Runtime: 184 ms
        Memory Usage: 18.7 MB
        """
        string_len = len(s)
        for i in range(int(string_len/2)):
            c = s[i]
            s[i] = s[string_len - i - 1]
            s[string_len - i - 1] = c

    def use_reverse(self, s: List[str]) -> None:
        """
        Runtime: 192 ms
        Memory Usage: 18.2 MB
        """
        s.reverse()