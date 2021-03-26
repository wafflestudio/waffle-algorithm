//
// Created by Hank Choi on 2021/03/20.
//

class Solution
{
public:
  vector <vector<int>> threeSum(vector<int> &nums)
  {
    int sum;
    sort(nums.begin(), nums.end());
    for (auto l = nums.begin(); l < nums.end(); l++) {
      this->twoSum(nums,-(*l))
    }
  }

  vector<int> twoSum(vector<int> &nums, int target)
  {
    int index = 0;
    vector <pair<int, int>> num_index;
    for (int num:nums) {
      num_index.push_back({num, index++});
    }
    auto l = num_index.begin(), r = num_index.end() - 1;
    while (l != r) {
      sum = l->first + r->first;
      if (sum > target) {
        r--;
      } else if (sum < target) {
        l++;
      } else {
        return {l->second, r->second};
      }
    }
    return {};
  }

};