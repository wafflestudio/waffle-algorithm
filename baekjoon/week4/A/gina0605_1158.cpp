// 48ms, 2056KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int nxt[MAXN], prv[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, K;

	cin >> N >> K;

	for(int i = 1; i <= N; i++) {
		nxt[i] = i % N + 1;
		prv[i % N + 1] = i;
	}
	int p = N;
	cout << "<";
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) p = nxt[p];
		cout << p;
		if(i != N - 1) cout << ", ";
		prv[nxt[p]] = prv[p];
		nxt[prv[p]] = nxt[p];
	}
	cout << ">\n";
	return 0;
}

