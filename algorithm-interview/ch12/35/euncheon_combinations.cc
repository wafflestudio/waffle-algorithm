/**
 * 24ms, 10MB
 * time complexity: O()
 * 
 */
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> comb;
    int total, num_needs;
public:
    void get_comb(int curr, int last) {
        if (curr > num_needs) {
            result.push_back(comb);
            return;
        }
        for(int i = last; i <= total; i++) {
            comb.push_back(i);
            get_comb(curr+1, i+1);        
            comb.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        total = n;
        num_needs = k;
        get_comb(1, 1);
        
        return result;
    }
};