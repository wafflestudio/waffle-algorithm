// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int S, A[9];

	cin >> S;
	for(int i = 0; i < 9; i++) cin >> A[i];

	for(int i = 0; i < 9; i++) S -= A[i];
	cout << S << "\n";
	return 0;
}
