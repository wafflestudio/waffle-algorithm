#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int start) {
  if (visited[start]) {
    return;
  }
  visited[start] = true;
  printf("%d ", start);

  for (int a : graph[start]) {
    if (not visited[a]) dfs(graph, visited, a);
  }
}

void bfs(vector<vector<int> > &graph, int start) {
  queue<int> q;
  vector<bool> visited(graph.size(), false);

  visited[start] = true;
  q.push(start);
  while (not q.empty()) {
    int a = q.front();
    q.pop();
    printf("%d ", a);
    for (int b : graph[a]) {
      if (not visited[b]) {
        visited[b] = true;
        q.push(b);
      }
    }
  }
}

int main(void) {
  int N, M, V;
  scanf("%d %d %d", &N, &M, &V);

  vector<vector<int> > graph(N + 1);
  vector<bool> visited(N + 1, false);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (vector<int> &g : graph) {
    sort(g.begin(), g.end());
  }
  dfs(graph, visited, V);
  printf("\n");
  bfs(graph, V);
  printf("\n");
  return 0;
}