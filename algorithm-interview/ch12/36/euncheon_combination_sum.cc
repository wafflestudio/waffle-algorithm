/**
 * 4ms, 11.1MB
 * time complexity: O(n!) ??
 */

class Solution {
 private:
  int target;
  vector<vector<int>> result;

 public:
  void dfs(vector<int>& candidates, int temp_sum, int index,
           vector<int>& path) {
    if (temp_sum > target) {
      return;
    }
    if (temp_sum == target) {
      result.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      dfs(candidates, temp_sum + candidates[i], i, path);
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->target = target;
    vector<int> a;
    dfs(candidates, 0, 0, a);

    return result;
  }
};