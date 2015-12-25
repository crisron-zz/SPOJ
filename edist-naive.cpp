#include <cstdio>
#include <cstring>

#define MAX 2000

char a[ MAX + 2 ], b[ MAX + 2 ];

int min( int x, int y ) {
    if( x < y ) {
        return x;
    }
    return y;
}

int computeEditDistance( int lena, int lenb ) {
    if( !lena ) {
        return lenb;
    }
    if( !lenb ) {
        return lena;
    }
    if( a[ lena - 1 ] == b[ lenb - 1 ] ) {
        return computeEditDistance( lena - 1, lenb - 1 );
    }
    int insert = computeEditDistance( lena, lenb - 1 ) + 1;
    int remove = computeEditDistance( lena - 1, lenb ) + 1;
    int replace = computeEditDistance( lena - 1, lenb - 1 ) + 1;
    return min( min( insert, remove ), replace );
}

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "\n%s\n%s", a, b );
        int lena = strlen( a );
        int lenb = strlen( b );
        printf( "%d\n", computeEditDistance( lena, lenb ) );
    }
    return 0;
}
