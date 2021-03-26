//
// Created by Hank Choi on 2021/03/26.
//
// 104ms 93.3MB

#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int max_profit=0;
    int min=prices[0];
    for(int price: prices){
      if(min>price){
        min = price;
      }
      if(max_profit < price - min){
        max_profit = price - min;
      }
    }
    return max_profit;
  }
};