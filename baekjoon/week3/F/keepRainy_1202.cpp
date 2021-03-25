//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 1202. 보석 도둑 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Gem { long m, v; };

// Set up : Functions Declaration
bool operator < (Gem u, Gem v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, K;
    cin >> N >> K;
    vector<Gem> G(N+K);
    for (int i=0; i<N; i++) {
        long m, v;
        cin >> m >> v;
        G[i] = {m, v};
    }
    for (int i=N; i<N+K; i++) {
        long c; cin >> c;
        G[i] = {c, -1};
    }

    // Process
    sort(G.begin(), G.end());
    priority_queue<long> que;

    long ans = 0;
    for (int i=0; i<N+K; i++) {
        auto [m, v] = G[i];
        if (v != -1) {
            que.push(v);
        } else {
            if (not(que.empty())) {
                ans += que.top();
                que.pop();
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Gem u, Gem v)
{
    return make_pair(u.m, -u.v) < make_pair(v.m, -v.v);
}
