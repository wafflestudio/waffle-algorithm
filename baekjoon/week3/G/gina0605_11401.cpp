// 36ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

const int MOD = 1000000007;

lint pw(lint a, int b) {
	lint ans = 1;
	for(int k = 1; k <= b; k *= 2, a = a * a % MOD) if(b & k) ans = ans * a % MOD;
	return ans;
}

lint fac(int n) {
	lint ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * i % MOD;
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, K;
	cin >> N >> K;
	cout << (fac(N) * pw(fac(K), MOD - 2) % MOD * pw(fac(N - K), MOD - 2) % MOD) << "\n";
	return 0;
}

