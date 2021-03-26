//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

/* 1406. 에디터 */

#include <iostream>
#include <algorithm>

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
    string L; cin >> L;
    string R;
    int M; cin >> M;
    for (int i=0; i<M; i++) {

        // Process
        char type; cin >> type;
        switch (type) {
            case 'L':
                if (not(L.empty())) {
                    R.push_back(L.back());
                    L.pop_back();
                } break;

            case 'D':
                if (not(R.empty())) {
                    L.push_back(R.back());
                    R.pop_back();
                } break;

            case 'B':
                if (not(L.empty())) {
                    L.pop_back();
                } break;

            case 'P':
                char c; cin >> c;
                L.push_back(c);
                break;

            default:
                throw invalid_argument("Invalid Command");
        }
    }

    // Process
    reverse(R.begin(), R.end());

    // Control : Output
    cout << L + R << endl;
}

// Helper Functions
/* None */

