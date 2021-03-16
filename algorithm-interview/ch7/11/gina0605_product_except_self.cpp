/*
238. Product of Array Except Self
20ms, 26.1MB
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int N = nums.size();
		vector<int> l(N + 2), r(N + 2);
		nums.insert(nums.begin(), 1);
		l[0] = 1;
		for(int i = 1; i <= N; i++) l[i] = l[i - 1] * nums[i];
		r[N + 1] = 1;
		for(int i = N; i > 0; i--) r[i] = r[i + 1] * nums[i];
		vector<int> ans;
		for(int i = 1; i <= N; i++) ans.push_back(l[i - 1] * r[i + 1]);
		return ans;
    }
};
