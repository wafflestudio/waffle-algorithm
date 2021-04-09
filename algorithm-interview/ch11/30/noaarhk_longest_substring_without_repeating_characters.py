class Solution:
    # subsequence - 불연속문자
    # def lengthOfLongestSubstring(self, s: str) -> int:
    #
    #     used = {}
    #     start = 0
    #
    #     for index, char in enumerate(s):
    #
    #         if char in used and start <= used[char]:
    #             start = used[char] + 1
    #
    #         used[char] = index
    #
    #     print(used)
    #     return len(used)

    # substring
    def lengthOfLongestSubstring(self, s: str) -> int:

        used = {}
        start = 0
        s_len = 0

        for index, char in enumerate(s):

            if char in used and start <= used[char]:
                start = used[char] + 1

            else:
                # ??
                s_len = max(s_len, index - start + 1)

            used[char] = index

        print(used)
        return s_len


if __name__ == '__main__':
    solution = Solution()
    print(solution.lengthOfLongestSubstring('abcabcbb'))
    print(solution.lengthOfLongestSubstring('bbbbb'))
    print(solution.lengthOfLongestSubstring('pwwkew'))
