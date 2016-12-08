#include <iostream>

#define MAXPARTIES 100
#define MAXBUDGET 500

using namespace std;

int main() {
    while( 1 ) {
        int budget, n; // n = number of parties
        int entranceFee[ MAXPARTIES + 2 ], fun[ MAXPARTIES + 2 ];
        cin >> budget >> n;
        if( !budget && !n ) {
            break;
        }
        for( int i = 0; i < n; ++i ) {
            cin >> entranceFee[ i ] >> fun[ i ];
        }

        int maxFun[ MAXBUDGET + 2 ][ MAXPARTIES + 2 ];
        int totalEntranceFee[ MAXBUDGET + 2 ][ MAXPARTIES + 2 ];
        for( int i = 0; i <= budget; ++i ) {
            for( int j = 0; j <= n; ++j ) {
                if( !i || !j ) {
                    maxFun[ i ][ j ] = 0;
                    totalEntranceFee[ i ][ j ] = 0;
                } else if( i - entranceFee[ j - 1 ] >= 0 ) {
                    int goToPartyFun = fun[ j - 1 ] + maxFun[ i - entranceFee[ j - 1 ] ][ j - 1 ];
                    int dontGoToPartyFun = maxFun[ i ][ j - 1 ];
                    int goToPartyFee = entranceFee[ j - 1 ] +
                                       totalEntranceFee[ i - entranceFee[ j - 1 ] ][ j - 1 ];
                    int dontGoToPartyFee = totalEntranceFee[ i ][ j - 1 ];
                    if( goToPartyFun > dontGoToPartyFun ) {
                        maxFun[ i ][ j ] = goToPartyFun;
                        totalEntranceFee[ i ][ j ] = goToPartyFee;
                    } else if( dontGoToPartyFun > goToPartyFun ) {
                        maxFun[ i ][ j ] = dontGoToPartyFun;
                        totalEntranceFee[ i ][ j ] = dontGoToPartyFee;
                    } else {
                        maxFun[ i ][ j ] = goToPartyFun;
                        totalEntranceFee[ i ][ j ] = min( goToPartyFee, dontGoToPartyFee );
                    }
                } else {
                    maxFun[ i ][ j ] = maxFun[ i ][ j - 1 ];
                    totalEntranceFee[ i ][ j ] = totalEntranceFee[ i ][ j - 1 ];
                }
            }
        }
        cout << totalEntranceFee[ budget ][ n ] << " " << maxFun[ budget ][ n ] << endl;
    }
    return 0;
}

