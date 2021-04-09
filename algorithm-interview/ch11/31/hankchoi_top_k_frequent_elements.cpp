#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> table;
    vector<pair<int, int>> table_v;
    vector<int> output;
    for (int num : nums) {
      table[num]++;
    }
    for (auto it = table.begin(); it != table.end(); it++)
      table_v.push_back(*it);

    sort(table_v.begin(), table_v.end(), compare);
    for (int j = 0; j < k; j++)
      output.push_back(table_v[j].first);
    return output;
  }
};
