/*
20. Valid Parenthesis
0ms
6.1MB
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
		for(auto c : s) {
			switch(c) {
			case ')':
				if(st.empty() || st.back() != '(') return false;
				st.pop_back();
				break;
			case '}':
				if(st.empty() || st.back() != '{') return false;
				st.pop_back();
				break;
			case ']':
				if(st.empty() || st.back() != '[') return false;
				st.pop_back();
				break;
			default:
				st.push_back(c);
			}
		}
		return st.empty();
    }
};

