/*
819. Most Common Word
4ms, 7.6MB
*/

typedef pair<int, string> pis;

#define eb emplace_back
#define fi first
#define se second

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
		map<string, int> cnt;
		for(auto a : banned) cnt[a] = -1000;
		int s = 0;
		for(int i = 0; i <= paragraph.size(); i++) {
			if('A' <= paragraph[i] && paragraph[i] <= 'Z')
				paragraph[i] += 'a' - 'A';
			if(paragraph[i] < 'a' || paragraph[i] > 'z') {
				if(i != s) cnt[paragraph.substr(s, i - s)]++;
				s = i + 1;
			}
		}
		string ans;
		int mx = 0;
		for(auto &p : cnt) if(p.se > mx) {
			ans = p.fi;
			mx = p.se;
		}
		return ans;
    }
};
