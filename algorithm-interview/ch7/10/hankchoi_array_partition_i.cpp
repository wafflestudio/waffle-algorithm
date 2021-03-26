//
// Created by Hank Choi on 2021/03/20.
//
// 48ms 28.2MB
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(),nums.end());
    for(auto iter = nums.begin();iter<nums.end();iter+=2) sum += *iter;
    return sum;
  }
};

int main(){
  vector<int> nums = {6,2,6,5,1,2};
  cout << Solution().arrayPairSum(nums);
}