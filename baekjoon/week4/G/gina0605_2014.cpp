// 592ms, 6640KB

#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

const int MAXK = 110;
const int MX = (1ll << 31) - 1;

int P[MAXK];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int K, N;

	cin >> K >> N;
	for(int i = 0; i < K; i++) cin >> P[i];

	set<int> pq;
	for(int i = 0; i < K; i++) pq.insert(P[i]);

	int x = 0;
	while(N--) {
		x = *pq.begin();
		pq.erase(pq.begin());
		for(int i = 0; i < K; i++) if(P[i] <= MX / x) {
			pq.insert(x * P[i]);
			if(pq.size() > N) pq.erase(prev(pq.end()));
		}
	}
	cout << x << "\n";
	return 0;
}

