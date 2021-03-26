#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stack;
        int volume = 0;
        int curr = 0;
        while (curr < height.size()) {
            while (not stack.empty() && height[stack.top()] < height[curr]) {
                int top = stack.top();
                stack.pop();
                
                if (stack.empty()) {
                    break;
                }
                
                int dist = curr - stack.top() - 1;
                int waters = min(height[curr], height[stack.top()]) - height[top];
                volume += dist * waters;
            }
            
            stack.push(curr++);            
        }
        
        return volume;
    }
};