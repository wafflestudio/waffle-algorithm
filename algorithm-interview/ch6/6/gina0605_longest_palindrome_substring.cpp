/*
5. Longest Palindromic Substring
24ms, 8.1MB
*/

#define pb push_back

class Solution {
public:
    string longestPalindrome(string s) {
		string s2 = "!";
		for(int i = 0; i < s.size(); i++) {
			s2.pb('*');
			s2.pb(s[i]);
		}
		s2.pb('*');
		s2.pb('@');
		int m, l = -1;
		for(int i = 1; i <= s.size() * 2 + 1; i++) {
			int j = 1;
			while(s2[i - j] == s2[i + j]) j++;
			if(j > l) {
				l = j - 1;
				m = i;
			}
		}
		string ans;
		for(int i = m - l + 1; i < m + l; i += 2) 
			ans.push_back(s2[i]);
		return ans;
    }
};
