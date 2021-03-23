// 40ms, 7292KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600010;

char S[MAXN];
int l[MAXN], r[MAXN];
int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int M;
	
	cin >> (S + 2) >> M;

	r[0] = 2;
	l[2] = 0;
	for(n = 3; S[n]; n++) {
		l[n] = n - 1;
		r[n - 1] = n;
	}
	r[n - 1] = 1;
	l[1] = n - 1;
	int p = 1;

	for(int i = 0; i < M; i++) {
		char c;
		cin >> c;
		switch(c) {
		case 'L':
			if(l[p] != 0) p = l[p];
			break;
		case 'D':
			if(p != 1) p = r[p];
			break;
		case 'B':
			if(l[p] != 0) {
				l[p] = l[l[p]];
				r[l[p]] = p;
			}
			break;
		case 'P':
			cin >> S[n];
			r[l[p]] = n;
			l[n] = l[p];
			l[p] = n;
			r[n] = p;
			n++;
		}
	}

	for(p = r[0]; p != 1; p = r[p]) cout << S[p];
	cout << "\n";
	return 0;
}

