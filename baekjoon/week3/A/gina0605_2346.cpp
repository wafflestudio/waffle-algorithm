// 0ms, 2028KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int A[MAXN];
int l[MAXN], r[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 1; i < N; i++) {
		l[i + 1] = i;
		r[i] = i + 1;
	}
	l[1] = N;
	r[N] = 1;

	int p = 1;
	for(int i = 0; i < N; i++) {
		cout << p << "\n";
		int x = l[p], y = r[p];
		r[x] = y;
		l[y] = x;
		int q = p;
		for(int j = 0; j < A[p]; j++) q = r[q];
		for(int j = 0; j > A[p]; j--) q = l[q];
		p = q;
	}
	return 0;
}

