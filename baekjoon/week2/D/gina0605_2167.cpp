// 12ms, 2768KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310;

int A[MAXN][MAXN], S[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M, K;

	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin >> A[i][j];

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
		S[i][j] = S[i][j - 1] + A[i][j];
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) S[i][j] += S[i - 1][j];

	cin >> K;
	while(K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		if(i > x) swap(i, x);
		if(j > y) swap(j, y);
		cout << (S[x][y] - S[i - 1][y] - S[x][j - 1] + S[i - 1][j - 1]) << "\n";
	}
	return 0;
}
