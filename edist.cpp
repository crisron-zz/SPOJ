#include <cstdio>
#include <cstring>

#define MAX 2000

char a[ MAX + 2 ], b[ MAX + 2 ];
int dp[ MAX + 2 ][ MAX + 2 ];

int min( int x, int y ) {
    if( x < y ) {
        return x;
    }
    return y;
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "\n%s\n%s", a, b );
        int lena = strlen( a );
        int lenb = strlen( b );
        int i, j;

        for( i = 0; i <= lena; ++i ) {
            // a has i characters, b has none
            dp[ i ][ 0 ] = i;
        }
        for( j = 0; j <= lenb; ++j ) {
            // b has j characters, a has none
            dp[ 0 ][ j ] = j;
        }

        for( i = 1; i <= lena; ++i ) {
            for( j = 1; j <= lenb; ++j ) {
                if( a[ i - 1 ] == b[ j - 1 ] ) {
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ];
                } else {
                    int insert = dp[ i ][ j - 1 ] + 1;
                    int remove = dp[ i - 1 ][ j ] + 1;
                    int replace = dp[ i - 1 ][ j - 1 ] + 1;
                    dp[ i ][ j ] = min( min( insert, remove ), replace );
                }
            }
        }
        printf( "%d\n", dp[ lena ][ lenb ] );
    }
    return 0;
}
