/*
316. Remove Duplicate Letters
4ms, 6.3MB
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
		int r[26];
		for(int i = 0; i < 26; i++) r[i] = -1;
		for(int i = 0; i < s.size(); i++) r[s[i] - 'a'] = i;

		string ans;
		bool chk[26];
		for(int i = 0; i < 26; i++) chk[i] = false;
		for(int i = 0; i < s.size(); i++) if(!chk[s[i] - 'a']) {
			while(!ans.empty() && ans.back() > s[i] && r[ans.back() - 'a'] > i) {
				chk[ans.back() - 'a'] = false;
				ans.pop_back();
			}
			ans.push_back(s[i]);
			chk[s[i] - 'a'] = true;
		}
		return ans;
    }
};
