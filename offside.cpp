#include <cstdio>
#include <algorithm>

#define MAX 11

using namespace std;

int main() {
    int a, d, i;
    int attacking[ MAX + 2 ], defending[ MAX + 2 ];
    while( 1 ) {
        scanf( "%d%d", &a, &d );
        if( !a && !d ) {
            break;
        }
        for( i = 0; i < a; ++i ) {
            scanf( "%d", &attacking[ i ] );
        }
        for( i = 0; i < d; ++i ) {
            scanf( "%d", &defending[ i ] );
        }
        sort( attacking, attacking + a );
        sort( defending, defending + d );
        if( attacking[ 0 ] < defending[ 1 ] ) {
            printf( "Y\n" );
        } else {
            printf( "N\n" );
        }
    }
    return 0;
}
