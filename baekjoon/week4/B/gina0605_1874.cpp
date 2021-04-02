// 20ms, 3560KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int A[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	vector<char> ans;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];

	int p = N - 1;
	vector<int> st;
	for(int i = N; i > 0; i--) {
		while(st.empty() || st.back() != i) {
			if(p < 0) {
				cout << "NO\n";
				return 0;
			}
			st.push_back(A[p--]);
			ans.push_back('-');
		}
		st.pop_back();
		ans.push_back('+');
	}

	for(int i = 2 * N - 1; i >= 0; i--) cout << ans[i] << "\n";
	return 0;
}

