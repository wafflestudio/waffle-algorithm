/*
125. Valid Palindrome
4ms, 7.3MB
*/

class Solution {
public:
    bool isPalindrome(string S) {
        int N = 0;
        for(int i = 0; S[i]; i++) {
            if(('0' <= S[i] && S[i] <= '9') || ('a' <= S[i] && S[i] <= 'z')) 
                S[N++] = S[i];
            else if('A' <= S[i] && S[i] <= 'Z')
                S[N++] = S[i] - 'A' + 'a';
        }

        for(int p = 0, q = N - 1; p < q; p++, q--)
            if(S[p] != S[q]) 
                return false;
        return true;
    }
};
