#include <cstdio>

int main() {
    long long n;
    scanf( "%lld", &n );
    if( !n || !( n & ( n - 1 ) ) ) {
        printf( "TAK\n" );
    } else {
        printf( "NIE\n" );
    }
    return 0;
}
