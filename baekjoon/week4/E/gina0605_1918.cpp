// 0ms, 2016KB

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

char S[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> S;

	vector<char> st;
	string ans;
	for(int i = 0; S[i]; i++) {
		if('A' <= S[i] && S[i] <= 'Z') ans.push_back(S[i]);
		else {
			if(S[i] == ')') {
				while(st.back() != '(') {
					ans.push_back(st.back());
					st.pop_back();
				}
				st.pop_back();
			}
			else {
				while(!st.empty() && S[i] != '(' && st.back() != '(' && (S[i] == '+' || S[i] == '-' || ((S[i] == '*' || S[i] == '/') && (st.back() == '*' || st.back() == '/')))) {
					ans.push_back(st.back());
					st.pop_back();
				}
				st.push_back(S[i]);
			}
		}
	}
	while(!st.empty()) {
		ans.push_back(st.back());
		st.pop_back();
	}
	cout << ans << "\n";
	return 0;
}

