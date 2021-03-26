//
// Created by Hank Choi on 2021/03/25.
//
// 16ms 25MB
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    long product_of_all = 1;
    bool zero_exists = false;
    int index_of_zero = 0;
    int index = 0;
    vector<int> result;
    for(int num:nums){
      if(num == 0){
        if(zero_exists)
          return vector<int>(nums.size());
        zero_exists = true;
        index_of_zero = index;
      }
      else
        product_of_all *= num;
      index++;
    }
    if (zero_exists){
      result = vector<int>(nums.size());
      result[index_of_zero] = product_of_all;
      return result;
    }
    for(int num:nums){
      result.push_back(product_of_all/num);
    }
    return result;
  }
};

int main(){
  vector<int> input = {1,2,3,4};
  for(int a:Solution().productExceptSelf(input)){
    cout << a << endl;
  }
  input = {-1,1,0,-3,3};
  for(int a:Solution().productExceptSelf(input)){
    cout << a << endl;
  }
}
