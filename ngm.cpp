#include <cstdio>

int main() {
    long long n;
    scanf( "%lld", &n );
    if( !n || ( n % 10 ) ) {
        //Write Nifikor's move
        printf( "1\n" );
        if( n ) {
            printf( "%lld\n", n % 10 ); 
        }
    } else {
        printf( "2\n" );
    }
    return 0;
}
