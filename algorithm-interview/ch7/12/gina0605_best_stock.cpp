/*
121. Best Time to Buy and Sell Stock
112ms, 93.1MB
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int mn = prices[0];
		int ans = 0;
		for(int i = 0; i < prices.size(); i++) {
			mn = min(mn, prices[i]);
			ans = max(ans, prices[i] - mn);
		}
		return ans;
    }
};
