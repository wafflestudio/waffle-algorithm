// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	char S[MAXN];
	
	cin >> S;
	for(int i = 0; S[i]; i++) if('A' <= S[i] && S[i] <= 'Z') cout << S[i];
	cout << "\n";
	return 0;
}
