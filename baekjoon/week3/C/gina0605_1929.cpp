// 12ms, 2992KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

bool isp[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int M, N;

	cin >> M >> N;

	for(int i = 2; i <= N; i++) isp[i] = true;
	for(int i = 2; i <= N; i++) if(isp[i])
		for(int j = i * 2; j <= N; j += i) isp[j] = false;

	for(int i = M; i <= N; i++) if(isp[i]) cout << i << "\n";
	return 0;
}

