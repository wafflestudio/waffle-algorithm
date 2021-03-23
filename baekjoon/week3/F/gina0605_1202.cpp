// 156ms, 7200KB

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long lint;

#define fi first
#define se second

const int MAXN = 300010;

pii jwl[MAXN];
int C[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, K;

	cin >> N >> K;
	for(int i = 0; i < N; i++) cin >> jwl[i].fi >> jwl[i].se;
	for(int i = 0; i < K; i++) cin >> C[i];

	sort(jwl, jwl + N);
	sort(C, C + K);
	priority_queue<int> pq;
	int p = 0;
	lint ans = 0;
	for(int i = 0; i < K; i++) {
		while(p < N && jwl[p].fi <= C[i]) {
			pq.push(jwl[p].se);
			p++;
		}
		if(!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << "\n";
	return 0;
}

