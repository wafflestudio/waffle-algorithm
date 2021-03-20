#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int num[52] = {0};
        bool is_odd_used = false;
        int result = 0;
        
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                num[c-'a'] += 1;
            }
            else {
                num[26+c-'A'] += 1;
            }
        }
        
        for (int i : num) {
            if (i%2 == 1) {
                if (not is_odd_used){
                    is_odd_used = true;
                    result += i;
                }
                else {
                    result += i-1;
                }
            }
            else {
                result += i;
            }
        }
        
        return result;
    }
};