/*
17. Letter Combinations of a Phone Number
0ms, 6.5MB
*/

class Solution {
public:
	vector<string> ans;
	string s = "";
	const char alph[12] = "00adgjmptw{";

	void f(string &d, int i) {
		if(i == d.size()) {
			ans.push_back(s);
			return;
		}
		for(int c = alph[d[i] - '0']; c < alph[d[i] - '0' + 1]; c++) {
			s.push_back(c);
			f(d, i + 1);
			s.pop_back();
		}
	}

    vector<string> letterCombinations(string digits) {
		if(!digits.empty()) f(digits, 0);
		return ans;
    }
};
