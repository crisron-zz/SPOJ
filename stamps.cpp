#include <cstdio>
#include <algorithm>

#define MAX 1000

using namespace std;

int main() {
    int testCases, friends, i, j, stampsNeeded, totalStampsOffered, stampsCollected;
    int stampsOffered[ MAX + 1 ];
    scanf( "%d", &testCases );
    for( j = 0; j < testCases; ++j ) {
        totalStampsOffered = 0;
        stampsCollected = 0;
        scanf( "%d%d", &stampsNeeded, &friends );
        for( i = 0; i < friends; ++i ) {
            scanf( "%d", &stampsOffered[ i ] );
            totalStampsOffered += stampsOffered[ i ];
        }
        if( totalStampsOffered < stampsNeeded ) {
            printf( "Scenario #%d:\nimpossible\n\n", j + 1 );
        } else {
            // Sort the stampsOffered array in decreasing order
            sort( stampsOffered, stampsOffered + friends );
            for( i = friends - 1; i >= 0; --i ) {
                if( stampsCollected >= stampsNeeded ) {
                    break;
                }
                stampsCollected += stampsOffered[ i ];
            }
            printf( "Scenario #%d:\n%d\n\n", j + 1, friends - ( i + 1 ) );
        }
    }
    return 0;
}
