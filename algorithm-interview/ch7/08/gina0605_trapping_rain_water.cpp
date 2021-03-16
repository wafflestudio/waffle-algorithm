/*
42. Trapping Rain Water
4ms, 14.4MB
*/

#define eb emplace_back

class Solution {
public:
    int trap(vector<int>& height) {
		int N = height.size();
		vector<int> lm(N), rm(N);
		if(N == 0) return 0;

		lm[0] = height[0];
		for(int i = 1; i < N; i++) lm[i] = max(lm[i - 1], height[i]);
		rm[N - 1] = height[N - 1];
		for(int i = N - 2; i >= 0; i--) rm[i] = max(rm[i + 1], height[i]);

		int ans = 0;
		for(int i = 0; i < N; i++) ans += min(lm[i], rm[i]) - height[i];
		return ans;
    }
};
