from collections import deque
import sys
import heapq

INF = 1e9


def dijkstra():
    q = [] # priority queue
    heapq.heappush(q, (0, s))
    distance[s] = 0  # 출발지

    while q:  # 큐가 비어있지 않는 동안 동작
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 방문된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드의 인접한 노드들을 확인하면서 거리 업데이트
        for i in graph[now]:
            new_dist = dist + graph[now][i]
            if new_dist < distance[i]:  # 해당 지점을 거치는 것이 거리가 짧은 경우
                distance[i] = new_dist
                heapq.heappush(q, (new_dist, i))


def bfs():
    q = deque()
    q.append(d) # 도착지부터 bfs시작
    while q:
        v = q.popleft()
        if v == s:  # 시작점 도달
            continue  # break하면 다른 최단 경로를 확인할 수 없다.
        for pre_v, pre_c in r_graph[v]:
            if distance[pre_v] + graph[pre_v][v] == distance[v]:
                if (pre_v, v) not in remove_list:
                    remove_list.append((pre_v, v))
                    q.append(pre_v)


if __name__ == "__main__":
    while True:
        n, m = map(int, sys.stdin.readline().split())
        if n == 0 and m == 0:  # n과 m이 0이면 종료
            break
        s, d = map(int, sys.stdin.readline().split())  # 출발지, 도착지 입력 받기
        
        graph = [dict() for _ in range(n)]     # 순방향 그래프
        r_graph = [[] for _ in range(n)]       # 역방향 그래프
        for _ in range(m):
            u, v, w = map(int, sys.stdin.readline().split())  # 도로 정보 입력
            graph[u][v] = w
            r_graph[v].append((u, w))  # 경로를 추적하기 위해서 역순 저장

        # 다익스트라 알고리즘을 사용하여 최단 거리 찾기
        distance = [INF] * n # 가중치 무한대로 초기화
        dijkstra()

        # BFS를 사용하여 최단 경로 찾아내기. 
        remove_list = list()
        bfs()

        # 최단 경로 제거
        for u, v in remove_list:
            del graph[u][v]

        # 다익스트라 알고리즘을 사용하여 거의 최단 경로 찾기
        distance = [INF] * n
        dijkstra()
        if distance[d] == INF:  # 거의 최단 경로가 없는 경우
            print(-1)
        else:
            print(distance[d])