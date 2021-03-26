//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 11401. 이항 계수 3 */

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
#define MOD (long)(1e9+7)

// Set up : Functions Declaration
long pow2(long n, int exp);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, K;
    cin >> N >> K;

    // Process
    long A = 1; /* N! */
    long B = 1; /* K!(N-K)! */

    for (int i=1; i<=N; i++) {
        A *= i, A %= MOD;
    }
    for (int i=1; i<=K; i++) {
        B *= i, B %= MOD;
    }
    for (int i=1; i<=N-K; i++) {
        B *= i, B %= MOD;
    }

    B = pow2(B, MOD-2);

    long ans = A * B;
    ans %= MOD;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
long pow2(long n, int exp)
{
    if (exp == 0) return 1;
    if (exp%2 == 1) return (pow2(n, exp-1) * n) % MOD;

    long h = pow2(n, exp/2);
    return h * h % MOD;
}
