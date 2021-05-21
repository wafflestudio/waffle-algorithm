#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int pre[MAXN], in[MAXN];

void f(int pidx, int iidx, int l) {
	if(l == 0) return;
	int r;
	for(int i = 0; i < l; i++) if(in[iidx + i] == pre[pidx]) r = i;
	f(pidx + 1, iidx, r);
	f(pidx + r + 1, iidx + r + 1, l - r - 1);
	cout << pre[pidx] << " ";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		for(int i = 0; i < N; i++) cin >> pre[i];
		for(int i = 0; i < N; i++) cin >> in[i];
		f(0, 0, N);
		cout << "\n";
	}
	return 0;
}
