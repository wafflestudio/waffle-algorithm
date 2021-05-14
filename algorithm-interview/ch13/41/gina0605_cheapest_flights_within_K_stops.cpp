class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
  		vector<int> dis(n, -1);
		dis[src] = 0;
		for(int i = 0; i < k + 1; i++) {
			vector<int> dis2 = dis;
			for(auto e : flights) if(dis[e[0]] != -1) {
				int t = dis[e[0]] + e[2];
				if(dis2[e[1]] == -1 || t < dis2[e[1]]) dis2[e[1]] = t;
			}
			swap(dis, dis2);
		}
		return dis[dst];
    }
};
