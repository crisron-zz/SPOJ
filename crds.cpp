#include <cstdio>

#define MAX 1000000
#define MOD 1000007

void precompute( int ans[] ) {
    int i;
    ans[ 0 ] = 0;
    for( i = 1; i <= MAX; ++i ) {
        ans[ i ] = ( ( i - 1 ) % MOD + ( 2 * i ) % MOD + ans[ i - 1 ] % MOD ) % MOD;
    }
}

int main() {
    int t;
    int ans[ MAX + 2 ];
    precompute( ans );
    scanf( "%d", &t );
    while( t-- ) {
        int n;
        scanf( "%d", &n );
        printf( "%d\n", ans[ n ] );
    }
    return 0;
}
