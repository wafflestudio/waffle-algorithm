//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 2346. 풍선 터뜨리기 */

#include <iostream>
#include <deque>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Balloon { int no, val; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    deque<Balloon> D(N);
    for (int i=0; i<N; i++) {
        int val; cin >> val;
        D[i] = {i+1, val};
    }

    // Process
    int idx = 0;
    while (true) {
        int val = D[idx].val;

        // Control : Output
        cout << D[idx].no << ' ';

        D.erase(D.begin()+idx);
        if (D.empty()) break;
        if (val > 0) { val--; }
        idx = (idx+val) % (int)D.size();
        if (idx < 0) { idx += D.size(); }
    }
}

// Helper Functions
/* None */

