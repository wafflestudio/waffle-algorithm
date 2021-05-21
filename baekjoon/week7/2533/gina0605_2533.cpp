#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int MAXN = 1000010;

vector<int> ed[MAXN];
int dp[MAXN][2];

void dfs(int x, int p) {
	dp[x][1] = 1;
	for(auto a : ed[x]) if(a != p) {
		dfs(a, x);
		dp[x][0] += dp[a][1];
		dp[x][1] += dp[a][0];
	}
	dp[x][0] = min(dp[x][0], dp[x][1]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		ed[a].eb(b);
		ed[b].eb(a);
	}

	dfs(1, 0);
	cout << dp[1][0] << "\n";
	return 0;
}

