// 80ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

vector<int> v[7];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, P;

	cin >> N >> P;

	int ans = 0;
	while(N--) {
		int a, b;
		cin >> a >> b;
		while(!v[a].empty() && v[a].back() > b) {
			v[a].pop_back();
			ans++;
		}
		if(v[a].empty() || v[a].back() != b) {
			v[a].push_back(b);
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}

