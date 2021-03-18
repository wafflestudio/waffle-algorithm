// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

bool f() {
	char S[MAXN];
	cin >> S;
	int cnt = 0;
	for(int i = 0; S[i]; i++) {
		cnt += S[i] == '(' ? 1 : -1;
		if(cnt < 0) return false;
	}
	return cnt == 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;

	cin >> T;
	while(T--) cout << (f() ? "YES" : "NO") << "\n";
	return 0;
}

