#include <cstdio>

int main() {
    long long n;
    scanf( "%lld", &n );
    // Checking if n is a power of 2
    if( !n || !( n & ( n - 1 ) ) ) {
        printf( "TAK\n" );
    } else {
        printf( "NIE\n" );
    }
    return 0;
}
