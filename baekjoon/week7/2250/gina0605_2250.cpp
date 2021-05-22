#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int lef[MAXN], rig[MAXN];
bool isr[MAXN];
int mn[MAXN], mx[MAXN];
int cnt;

void dfs(int x, int d) {
	if(lef[x] != -1) dfs(lef[x], d + 1);
	++cnt;
	if(!mn[d]) mn[d] = cnt;
	mx[d] = cnt;
	if(rig[x] != -1) dfs(rig[x], d + 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		cin >> lef[x] >> rig[x];
	}

	for(int i = 1; i <= N; i++) isr[i] = true;
	for(int i = 1; i <= N; i++) {
		if(lef[i] != -1) isr[lef[i]] = false;
		if(rig[i] != -1) isr[rig[i]] = false;
	}
	for(int i = 1; i <= N; i++) if(isr[i]) dfs(i, 1);

	int ans_dis, ans_wid = 0;
	for(int i = 1; i <= N; i++) {
		int t = mx[i] - mn[i] + 1;
		if(t > ans_wid) {
			ans_dis = i;
			ans_wid = t;
		}
	}
	cout << ans_dis << " " << ans_wid << "\n";
	return 0;
}

