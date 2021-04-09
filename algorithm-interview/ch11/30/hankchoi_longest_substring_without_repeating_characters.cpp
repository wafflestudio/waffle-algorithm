#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int appeared[255] = {
        0,
    };
    for (int k = 0; k < 255; k++) {
      appeared[k] = -1;
    }
    int index = 0;
    int start_point = -1;
    int longest = 0;
    for (char c : s) {
      int length;
      if (appeared[c] == -1) {
        length = index - start_point;
      } else {
        length = min(index - appeared[c], index - start_point);
        start_point = max(start_point, appeared[c]);
      }
      appeared[c] = index;
      longest = max(longest, length);

      index++;
    }
    return longest;
  }
};
