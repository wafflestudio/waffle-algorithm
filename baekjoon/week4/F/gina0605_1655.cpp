// 28ms, 3224KB

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int A[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	priority_queue<int> s;
	priority_queue<int, vector<int>, greater<int>> l;
	for(int i = 1; i <= N; i++) {
		if(i == 1 || A[i] < s.top()) {
			s.push(A[i]);
			while(s.size() > (i + 1) / 2) {
				l.push(s.top());
				s.pop();
			}
		}
		else {
			l.push(A[i]);
			while(s.size() < (i + 1) / 2) {
				s.push(l.top());
				l.pop();
			}
		}
		cout << s.top() << "\n";
	}
	return 0;
}

