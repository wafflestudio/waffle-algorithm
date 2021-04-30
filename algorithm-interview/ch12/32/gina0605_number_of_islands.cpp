/*
200. Number of Islands
12ms, 9.3MB
*/


class Solution {
public:
	const int mm[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int N, M;

	void f(vector<vector<char>> &g, int i, int j) {
		g[i][j] = '0';
		for(int k = 0; k < 4; k++) {
			int ii = i + mm[k][0], jj = j + mm[k][1];
			if(0 <= ii && ii < N && 0 <= jj && jj < M && g[ii][jj] == '1')
				f(g, ii, jj);
		}
	}

    int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
		N = grid.size(), M = grid[0].size();
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
			if(grid[i][j] == '1') {
				cnt++;
				f(grid, i, j);
			}
		return cnt;
    }
};
