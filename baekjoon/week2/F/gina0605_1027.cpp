// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

typedef __int128_t llint;

int N;
int H[55], Hi[55];

int f(int h[], int x) {
	int ans = 0;
	for(int i = x + 1; i < N; i++) {
		bool b = true;
		for(int j = x + 1; j < i; j++)
			if((llint)h[j] * (i - x) >= (llint)h[x] * (i - j) + (llint) h[i] * (j - x))
				b = false;
		if(b) ans++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++) cin >> H[i];

	for(int i = 0; i < N; i++) Hi[i] = H[N - i - 1];

	int ans = 0;
	for(int i = 0; i < N; i++) ans = max(ans, f(H, i) + f(Hi, N - i - 1));
	cout << ans << "\n";
	return 0;
}

