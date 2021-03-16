/*
937. Reorder Data in Log Files
16ms, 16.2MB
*/

typedef pair<int, string> pis;

#define eb emplace_back
#define fi first
#define se second

class Solution {
private:
	bool is_num(string s) {
		int idx = s.find(' ') + 1;
		return '0' <= s[idx] && s[idx] <= '9';
	}
	
	string split(string &s) {
		return s.substr(s.find(' ') + 1, s.size());
	}
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
		vector<int> v;
		for(int i = 0; i < logs.size(); i++) v.eb(i);
		sort(v.begin(), v.end(), [&](const int a, const int b) {
			if(is_num(logs[a])) {
				if(is_num(logs[b])) return a < b;
				else return false;
			}
			else {
				if(is_num(logs[b])) return true;
				else {
					string as = split(logs[a]), bs = split(logs[b]);
					return as == bs ? logs[a] < logs[b] : as < bs;
				}
			}
		});
		vector<string> ans;
		for(int i = 0; i < logs.size(); i++) ans.eb(logs[v[i]]);
		return ans;
    }
};
