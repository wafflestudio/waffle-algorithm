/*
39. Combinational Sum
8ms, 11MB
*/

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> v;

	void f(vector<int> &cand, int tar, int i) {
		if(tar == 0) ans.push_back(v);
		for(; i < cand.size(); i++) if(cand[i] <= tar) {
			v.push_back(cand[i]);
			f(cand, tar - cand[i], i);
			v.pop_back();
		}
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		f(candidates, target, 0);
		return ans;
    }
};
