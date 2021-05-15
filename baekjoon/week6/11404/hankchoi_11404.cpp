#include <iostream>
#include <algorithm>

using namespace std;

int smallest_cost[100][100];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            smallest_cost[i][j] = 10000001;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        smallest_cost[i][i] = 0;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        smallest_cost[a-1][b-1] = min(smallest_cost[a-1][b-1], c);
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                smallest_cost[i][j] = min(smallest_cost[i][j], smallest_cost[i][k] + smallest_cost[k][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << (smallest_cost[i][j] == 10000001 ? 0 : smallest_cost[i][j]) << " ";
        cout << endl;
    }
}

