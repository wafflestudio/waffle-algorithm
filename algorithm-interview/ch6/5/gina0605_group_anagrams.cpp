/*
49. Group Anagrams
32ms, 20.8MB
*/

#define eb emplace_back
#define fi first
#define se second

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
		for(auto s : strs) {
			string s2 = s;
			sort(s2.begin(), s2.end());
			m[s2].eb(s);
		}
		vector<vector<string>> ans;
		for(auto a : m) ans.eb(a.se);
		return ans;
    }
};
