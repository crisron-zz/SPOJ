/*
 Suppose A is the first player and B is the second. If A picks 1 in the first turn, and B picks some x out of the remaining numbers, and B wins, then A could just have picked x in the first turn and won. So, A will always win i.e. the player who starts the game.
*/
#include <cstdio>

int main() {
    int t;
    scanf( "%d", &t );
    while( t-- ) {
        int n;
        scanf( "%d", &n );
        int p;
        scanf( "%d", &p );
        if( p ) {
            printf( "Pagfloyd " );
        } else {
            printf( "Airborne " );
        }
        printf( "wins.\n" );
    }
    return 0;
}
