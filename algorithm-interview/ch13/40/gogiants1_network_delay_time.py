class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list) # 그래프 생성
        
        for u, v, w in times: # adjacent list
            graph[u].append((v, w))
        
        pq = [(0, k)]
        dist = collections.defaultdict(int)
        
        while pq: 
            t, node = heapq.heappop(pq)
            if node not in dist:
                dist[node] = t
                for v,w in graph[node]:
                    alt = t + w
                    heapq.heappush(pq, (alt, v))
                    
        if len(dist) == n:
            return max(dist.values())
        return -1