class Solution {
  vector<vector<int>> result;

  void get_subset_by_dfs(vector<int>& nums, vector<int>& path, int index) {
    result.push_back(path);
    for (int i = index; i < nums.size(); i++) {
      path.push_back(nums[i]);
      get_subset_by_dfs(nums, path, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    get_subset_by_dfs(nums, path, 0);
    return result;
  }
};