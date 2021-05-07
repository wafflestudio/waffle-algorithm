#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

#define eb emplace_back

vector<int> ed[MAXN];
bool chk[MAXN];

void dfs(int x) {
	chk[x] = true;
	for(auto a : ed[x]) if(!chk[a]) dfs(a);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;

	cin >> N >> M;
	while(M--) {
		int a, b;
		cin >> a >> b;
		ed[a].eb(b);
		ed[b].eb(a);
	}

	dfs(1);
	int cnt = 0;
	for(int i = 1; i <= N; i++) if(chk[i]) cnt++;
	cout << (cnt - 1) << "\n";
	return 0;
}

