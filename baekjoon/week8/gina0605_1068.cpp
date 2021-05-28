#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int MAXN = 55;

int P[MAXN];
vector<int> chi[MAXN];

int dfs(int x) {
	if(chi[x].empty()) return 1;
	int ans = 0;
	for(auto a : chi[x]) ans += dfs(a);
	return ans;
}

int main() {
	int N;
	int del, r;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> P[i];
	cin >> del;

	for(int i = 0; i < N; i++) {
		if(P[i] == -1) r = i;
		else if(i != del) chi[P[i]].eb(i);
	}

	cout << (del == r ? 0 : dfs(r)) << "\n";
	return 0;
}

