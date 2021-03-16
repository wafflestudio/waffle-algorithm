/*
15. 3Sum
80ms, 22.3MB
*/

#define all(v) (v).begin(),(v).end()
#define eb emplace_back

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int N = nums.size();
		sort(all(nums));

		vector<vector<int>> v;
		for(int i = 0; i < N - 2; i++) if(i == 0 || nums[i] != nums[i - 1]) {
			for(int j = i + 1, k = N - 1; j < k;) {
				int x = nums[i] + nums[j] + nums[k];
				if(x == 0) {
					v.eb(vector<int>({nums[i], nums[j], nums[k]}));
					j++;
					k--;
				}
				else if(x < 0) j++;
				else k--;
			}
		}
		v.resize(unique(all(v)) - v.begin());
		return v;
    }
};
