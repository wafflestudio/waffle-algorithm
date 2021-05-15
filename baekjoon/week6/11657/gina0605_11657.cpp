#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

const int MAXN = 510;
const int MAXM = 6010;
const lint LINF = 1ll << 60;

int A[MAXM], B[MAXM], C[MAXM];
lint dis[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;

	cin >> N >> M;
	for(int i = 0; i < M; i++) cin >> A[i] >> B[i] >> C[i];

	for(int i = 2; i <= N; i++) dis[i] = LINF;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(dis[A[j]] != LINF) 
		dis[B[j]] = min(dis[B[j]], dis[A[j]] + C[j]);
	
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		if(dis[A[j]] != LINF && dis[A[j]] + C[j] < dis[B[j]]) {
			cout << "-1\n";
			return 0;
		}
	for(int i = 2; i <= N; i++) cout << (dis[i] == LINF ? -1 : dis[i]) << "\n";
	return 0;
}

