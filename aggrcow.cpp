/*
 Read this first: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
 Then this: https://www.quora.com/What-is-the-correct-approach-to-solve-the-SPOJ-problem-Aggressive-cow/answer/Raziman-T-V
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Checks whether we can place c cows where any 2 consecutive cows are at
// least x distance apart
bool F( vector<int> stalls, int c, int x ) {
    int cowsPlaced = 1, lastPos = stalls[ 0 ];
    for( int i = 1; i < stalls.size(); ++i ) {
        if( stalls[ i ] - lastPos >= x ) {
            cowsPlaced++;
            if( cowsPlaced == c ) {
                return 1;
            }
            lastPos = stalls[ i ];
        }
    }
    return 0;
}

int largestMinDist( vector<int> stalls, int n, int c ) {
    sort( stalls.begin(), stalls.end() );
    int lo = 0;
    int hi = stalls[ n - 1 ] - stalls[ 0 ] + 1;

    while( hi - lo > 1 ) {
        int mid = lo + ( hi - lo ) / 2;
        if( F( stalls, c, mid ) ) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int t;
    int n, c;
    cin >> t;
    while( t-- ) {
        cin >> n >> c;
        vector<int> stalls;
        int i, tmp;
        for( i = 0; i < n; ++i ) {
            cin >> tmp;
            stalls.push_back( tmp );
        }
        cout << largestMinDist( stalls, n, c ) << endl;
    }
    return 0;
}
