//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 16120. PPAP */

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
    string S; cin >> S;

    // Process
    string A;
    for (char c : S) {
        A.push_back(c);
        int N = A.length();
        if (N >= 4) {
            if (A[N-1] == 'P' &&
                A[N-2] == 'A' &&
                A[N-3] == 'P' &&
                A[N-4] == 'P') {
                A.pop_back();
                A.pop_back();
                A.pop_back();
            }
        }
    }

    // Control : Output
    cout << ((A == "P") ? "PPAP" : "NP") << endl;
}

// Helper Functions
/* None */

