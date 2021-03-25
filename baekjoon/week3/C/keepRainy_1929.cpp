//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 1929. 소수 구하기 */

#include <iostream>
#include <cstring>

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
    int M, N;
    cin >> M >> N;

    // Process
    bool isPrime[N+1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i<=N; i++) {
        if (isPrime[i]) {
            
            // Control : Output
            if (i >= M) { cout << i << endl; }

            for (int j=i+i; j<=N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

// Helper Functions
/* None */

