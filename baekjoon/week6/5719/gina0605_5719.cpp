#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define fi first
#define se second
#define eb emplace_back

const int MAXN = 510;
const int MAXM = 10010;

int N, M, S, E;
int dis[MAXN], rdis[MAXN];
vector<pii> ed[MAXN], red[MAXN], ned[MAXN];

void dijkstra(vector<pii> ed[], int dis[], int S) {
	for(int i = 0; i < N; i++) dis[i] = -1;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[S] = 0;
	pq.push(pii(0, S));
	while(!pq.empty()) {
		pii t = pq.top();
		pq.pop();
		if(t.fi != dis[t.se]) continue;
		for(auto a : ed[t.se]) {
			int d = t.fi + a.fi;
			if(dis[a.se] == -1 || d < dis[a.se]) {
				dis[a.se] = d;
				pq.push(pii(d, a.se));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while(true) {
		cin >> N >> M;
		if(N == 0) return 0;
		cin >> S >> E;
		for(int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			ed[a].eb(c, b);
			red[b].eb(c, a);
		}

		dijkstra(ed, dis, S);
		dijkstra(red, rdis, E);
		for(int i = 0; i < N; i++) for(auto a : ed[i]) 
			if(dis[i] + rdis[a.se] + a.fi != dis[E]) ned[i].eb(a.fi, a.se);
		dijkstra(ned, dis, S);
		cout << dis[E] << "\n";
		for(int i = 0; i < N; i++) {
			ed[i].clear();
			red[i].clear();
			ned[i].clear();
		}
	}
}

