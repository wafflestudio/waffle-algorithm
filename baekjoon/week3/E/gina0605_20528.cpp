// 0ms, 2028KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXL = 110;

char S[MAXN][MAXL];
int l[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> S[i];
	for(int i = 0; i < N - 1; i++) if(S[i][0] != S[i + 1][0]) {
		cout << "0\n";
		return 0;
	}
	cout << "1\n";
	return 0;
}

