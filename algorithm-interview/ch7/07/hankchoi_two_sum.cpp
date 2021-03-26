//
// Created by Hank Choi on 2021/03/20.
//
// 4ms
// 9.3MB
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int sum;
    int index=0;
    vector<pair<int,int>> num_index;
    for(int num:nums){
      num_index.push_back({num,index++});
    }
    sort(num_index.begin(),num_index.end());
    auto l=num_index.begin(), r=num_index.end()-1;
    while(l!=r){
      sum =l->first+r->first;
      if(sum > target){
        r--;
      }
      else if(sum<target){
        l++;
      }
      else{
        return {l->second,r->second};
      }
    }
    return {};
  }
};


int main(){
  vector<int> nums = {3,2,4};
  vector<int> a =Solution().twoSum(nums,6);
  cout << a[0] << a[1];
}