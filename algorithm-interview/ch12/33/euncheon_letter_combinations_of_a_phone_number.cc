/**
 * DFS
 * 
 * 0ms, 6.6MB 
 * time complexity: O(m^n * n! / (m! * (n-m)!) * m) =>  O(4^n)
 * n: length of input string(digits)
 * m: length of one digit string('7': pqrs => 4)
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> letters = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations;

public:
    void dfs(string& digits, string curr_comb, int index) {
        if (index == digits.length()) {
            combinations.push_back(curr_comb);
            return;
        }
        
        int curr_digit = digits[index] - '2';
        for(int i = 0; i < letters[curr_digit].size(); i++) {
            dfs(digits, curr_comb + letters[curr_digit][i], index+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return combinations;
        
        dfs(digits, "", 0);
        
        return combinations;
    }
};