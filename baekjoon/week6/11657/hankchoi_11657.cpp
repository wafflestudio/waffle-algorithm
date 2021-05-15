#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};
const int COST_MAX = 50000001;
long time_cost[500];
int n,m;
struct Edge edges[6000];

void relax_all_edge() {
    for(int i=0;i<m;i++)
        if(time_cost[edges[i].u] != COST_MAX)
            time_cost[edges[i].v] = min(time_cost[edges[i].v], time_cost[edges[i].u] + edges[i].w);
}
bool has_negative_cycle() {
    for(int i=0;i<m;i++)
        if(time_cost[edges[i].u] != COST_MAX && time_cost[edges[i].v] > time_cost[edges[i].u] + edges[i].w)
            return true;
    return false;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        time_cost[i] = COST_MAX;
    time_cost[0] = 0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        struct Edge e = {a-1,b-1,c};
        edges[i] = e;
        if (a == 1)
            time_cost[b-1] = c;
    }

    for(int i=0;i<n;i++) {
        relax_all_edge();
    }
    if(has_negative_cycle()) {
        cout << "-1\n";
    }
    else {
        for(int i=1; i<n; i++)
            cout << (time_cost[i] == COST_MAX ? -1 : time_cost[i]) << "\n";
    }
    return 0;
}

