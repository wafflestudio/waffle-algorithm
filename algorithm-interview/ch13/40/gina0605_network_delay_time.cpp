class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1);
		for(int i = 1; i <= n; i++) dis[i] = -1;
		dis[k] = 0;
		for(int i = 0; i < n; i++) for(auto e : times) if(dis[e[0]] != -1) {
			int t = dis[e[0]] + e[2];
			if(dis[e[1]] == -1 || dis[e[1]] > t) dis[e[1]] = t;
		}
		for(int i = 1; i <= n; i++) if(dis[i] == -1) return -1;
		int ans = -1;
		for(int i = 1; i <= n; i++) ans = max(ans, dis[i]);
		return ans;
    }
};
