/*
739. Daily Temperatures
52ms, 41.5MB
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> ans(T.size());
		vector<int> st;
		for(int i = 0; i < T.size(); i++) {
			while(!st.empty() && T[st.back()] < T[i]) {
				ans[st.back()] = i - st.back();
				st.pop_back();
			}
			st.push_back(i);
		}
		return ans;
    }
};
