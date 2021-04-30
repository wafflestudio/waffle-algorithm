/*
77. Combinations
4ms, 8.8MB
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> v;
        for(int i = 1; i <= k; i++) v.push_back(i);
		ans.push_back(v);
		while(v[0] <= n - k) {
			int i = 0;
			while(i < k - 1 && v[i + 1] == v[i] + 1) i++;
			v[i]++;
			for(int j = 0; j < i; j++) v[j] = j + 1;
			ans.push_back(v);
		}
		return ans;
    }
};
