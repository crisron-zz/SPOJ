#include <cstdio>

#define MAX 100000

int main() {
    int n, i, arr[ MAX + 2 ], hash[ MAX + 2 ];
    while( 1 ) {
        scanf( "%d", &n );
        if( !n ) {
            break;
        }
        for( i = 0; i < n; ++i ) {
            scanf( "%d", &arr[ i ] );
            hash[ arr[ i ] ] = i + 1;
        }
        for( i = 0; i < n; ++i ) {
            if( hash[ i + 1 ] != arr[ i ] ) {
                printf( "not ambiguous\n" );
                break;
            }
        }
        if( i == n ) {
            printf( "ambiguous\n" );
        }
    }
    return 0;
}
