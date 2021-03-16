/*
1. Two Sum
8ms, 9.3MB
*/

typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define eb emplace_back
#define fi first
#define se second

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<pii> v;
		for(int i = 0; i < nums.size(); i++) v.eb(nums[i], i);
        sort(all(v));
		for(int i = 0, j = v.size() - 1;;) {
			int x = v[i].fi + v[j].fi;
			if(x == target)
				return vector<int>({v[i].se, v[j].se});
			else if(x < target) i++;
			else j--;
		}
    }
};
