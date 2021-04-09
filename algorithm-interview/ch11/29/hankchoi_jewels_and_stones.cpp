#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    int map[255] = {
        0,
    };
    int count = 0;
    for (char jewel : jewels) {
      map[jewel] = 1;
    }
    for (char stone : stones) {
      if (map[stone] == 1)
        count++;
    }
    return count;
  }
};
