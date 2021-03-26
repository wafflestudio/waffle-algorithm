
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int max_h = 0;
    int length = height.size();
    int sum = 0;
    vector<int> lm, rm(length);
    for (int h:height) {
      if (h < max_h) {
        lm.push_back(max_h);
      } else {
        lm.push_back(h);
        max_h = h;
      }
    }
    max_h = 0;
    for (int right = length-1; right >= 0; right--) {
      if (height[right] < max_h) {
        rm[right] = max_h;
      } else {
        rm[right] = height[right];
        max_h=height[right];
      }
    }
    auto l = lm.begin(), r = rm.begin();
    for (int h:height) {
      sum += min(*l, *r) - h;
      l++;
      r++;
    }
    return sum;
  }
};