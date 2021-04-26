/**
 * 0ms, 7.9MB
 * time complexity: O(n!)
 */
#include <vector>
using namespace std;

// class Solution {
// private:
//     int nums_length;
//     vector<vector<int> > result;
    
// public:
//     void dfs(vector<int>& nums, vector<int>& temp, 
//              vector<bool>& visited, int curr, int left) {

        
//         visited[curr] = true;
//         temp.push_back(nums[curr]);
        
//         if (left-1 == 0) {
//             result.push_back(temp);
//             visited[curr] = false;
//             temp.pop_back();
//             return;
//         }
        
//         for(int i=0; i<nums_length; i++) {
//             if (not visited[i]) {
//                 dfs(nums, temp, visited, i, left-1);
//             }
//         }
        
//         visited[curr] = false;
//         temp.pop_back();
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         if (nums.empty()) return result;
        
//         nums_length = nums.size();
//         vector<bool> visited(nums_length, false);
//         vector<int> temp(0);
        
//         for(int i=0; i<nums_length; i++) {
//             dfs(nums, temp, visited, i, nums_length);
//         }
        
//         return result;
//     }
// };

// much simpler code
class Solution {
    vector<vector<int> > result;
public:
    void dfs(vector<int>& nums, int curr) {
        if (curr >= nums.size()) {
            result.push_back(nums);
        }
        for(int i = curr; i < nums.size(); i++) {
            swap(nums[curr], nums[i]);
            dfs(nums, curr + 1);
            swap(nums[curr], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};