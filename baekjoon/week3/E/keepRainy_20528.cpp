//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 20528. 끝말잇기 */

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    string S[N];
    for (int i=0; i<N; i++)
        cin >> S[i];

    // Process
    bool isPossible = true;
    for (int i=0; i<N-1; i++) {
        if (S[i].front() != S[i+1].front()) {
            isPossible = false;
            break;
        }
    }

    // Control : Output
    cout << ((isPossible) ? 1 : 0) << endl;
}

// Helper Functions
/* None */

