"""
3. Longest Substring Without Repeating Characters
"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = {}
        mx_len = start = 0
        for i, c in enumerate(s):
            if c in used and start <= used[c]:
                start = used[c] + 1
            else:
                mx_len = max(mx_len, i - start + 1)
            
            used[c] = i
            
        return mx_len