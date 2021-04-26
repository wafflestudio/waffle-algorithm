class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool jewel_index[52] = {false, };
        int count = 0;
        
        for (char c : jewels) {
            if (c < 'a') {
                jewel_index[c-'A'] += 1;
            }
            else {
                jewel_index[c-'a' + 26] += 1;
            }
        }
        
        for (char c : stones) {
            if (c < 'a') {
                count += jewel_index[c-'A'];
            }
            else {
                count += jewel_index[c-'a' + 26];
            }
        }
        return count;
    }
};