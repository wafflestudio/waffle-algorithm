/*
56ms, 41.6MB
n: size of input vector
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> temp_stack; 
        vector<int> result(T.size(), 0);
        
        for (int i=0; i<T.size(); i++) {
            int curr = T[i];

            while ((not temp_stack.empty()) && T[temp_stack.top()] < curr) {
                result[temp_stack.top()] = i-temp_stack.top();
                temp_stack.pop();
            }
            
            temp_stack.push(i);
            
        }
        
        return result;
    }
};