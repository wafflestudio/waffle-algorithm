// 0ms, 2116KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

char c[MAXN];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int s = 0, ans = 0;

	cin >> c;
	for(int i = 0; c[i]; i++) {
		if(c[i] == '(') s++;
		else {
			s--;
			if(i > 0 && c[i - 1] == '(') ans += s;
			else ans++;
		}
    }
	cout << ans << "\n";
    return 0;
}


