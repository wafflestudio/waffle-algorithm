// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

int A[11], ans[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int i = 1; i <= N; i++) for(int j = 0;; j++)
		if(ans[j] == 0 && A[i]-- == 0) {
			ans[j] = i;
			break;
		}

	for(int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}

