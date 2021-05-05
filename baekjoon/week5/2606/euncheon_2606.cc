#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int count = 0;

void bfs(vector<vector<int> > &graph, vector<bool> &visited) {
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (not q.empty()) {
    int cur = q.front();
    q.pop();
    for (int next : graph[cur]) {
      if (not visited[next]) {
        count++;
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main(void) {
  int num_nodes;
  int num_edges;
  scanf("%d", &num_nodes);
  scanf("%d", &num_edges);
  vector<vector<int> > graph(num_nodes + 1);
  vector<bool> visited(num_nodes + 1, false);
  for (int i = 0; i < num_edges; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs(graph, visited);
  printf("%d\n", count);
  return 0;
}