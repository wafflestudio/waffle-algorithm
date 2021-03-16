/*
561. Array Partition 1
52ms, 28.2MB
*/

#define all(v) (v).begin(),(v).end()

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		sort(all(nums));
		int sum = 0;
		for(int i = 0; i < nums.size(); i += 2) sum += nums[i];
		return sum;
    }
};
