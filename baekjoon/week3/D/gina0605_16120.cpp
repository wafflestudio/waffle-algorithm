// 8ms, 2992KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

char S[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> S;
	for(N = 0; S[N]; N++);
	if(S[0] == 'A' || S[N - 1] == 'A') {
		cout << "NP\n";
		return 0;
	}
	int p = 1;
	for(int i = 1; i < N; i++)  
		if((p += (S[i] == 'P' ? 1 : -2)) < 0 || (S[i] == 'A' && S[i - 1] == 'A')) {
			cout << "NP\n";
			return 0;
		}
	if(p != 1) cout << "NP\n";
	else cout << "PPAP\n";
}

