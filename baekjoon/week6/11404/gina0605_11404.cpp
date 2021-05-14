#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int INF = 10000010;

int dis[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++)
		dis[i][j] = i == j ? 0 : INF;
	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dis[a][b] = min(dis[a][b], c);
	}
	
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++)
		for(int k = 1; k <= N; k++) {
			dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
		}

	for(int i = 1; i <= N; i++)  {
		for(int j = 1; j <= N; j++) cout << (dis[i][j] % INF) << " ";
		cout << "\n";
	}
	return 0;
}

