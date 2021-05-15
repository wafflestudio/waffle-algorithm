import collections
import heapq
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list)

        Q = [(0, k)]  # heapq (해당 노드까지의 시간, 해당노드 )
        visited = collections.defaultdict(int)  # { 노드 : 해당 노드까지 걸리는 시간 }

        for u, v, w in times:
            # 출발 : 도착지 , 도착지까지 걸리는 시간을 그래프로 표현
            graph[u].append((v, w))

        while Q:
            time, node = heapq.heappop(Q)
            if node not in visited:
                visited[node] = time

                if node not in graph:
                    continue

                for v, w in graph[node]:
                    temp = time + w
                    heapq.heappush(Q, (temp, v))

        # 모두 방문했는지 판단
        if len(visited) == n:
            # 최단거리로 탐색했을 때 가장 오래걸린시간
            return max(visited.values())

        return -1


if __name__ == '__main__':
    times = [
        [2, 1, 1],
        [2, 3, 1],
        [3, 4, 1],
    ]

    N = 4
    k = 2

    solution = Solution()
    print(solution.networkDelayTime(times, N, k))
