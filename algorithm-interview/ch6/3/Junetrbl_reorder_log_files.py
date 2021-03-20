from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        """
        Runtime: 24 ms
        Memory Usage: 14.4 MB
        """
        letter_logs = []
        number_logs = []

        for log in logs:
            last = log.split(' ')[-1]
            if last.isdigit():
                number_logs.append(log)
            else:
                letter_logs.append(log)

        letter_logs = sorted(
            letter_logs, key=lambda x: (x.split()[1:], x.split()[0]))

        return letter_logs + number_logs