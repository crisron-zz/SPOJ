#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int t, tc;
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d\n", &tc );
        string str;
        getline( cin, str );
        unordered_map<string, int> hashTable;
        hashTable[ "TTT" ] = 0;
        hashTable[ "TTH" ] = 0;
        hashTable[ "THT" ] = 0;
        hashTable[ "THH" ] = 0;
        hashTable[ "HTT" ] = 0;
        hashTable[ "HTH" ] = 0;
        hashTable[ "HHT" ] = 0;
        hashTable[ "HHH" ] = 0;
        int i;
        for( i = 0; i < 38; ++i ) {
            string toss = str.substr( i, 3 );
            hashTable[ toss ]++;
        }
        printf( "%d", tc );
        auto it = hashTable.end();
        do {
            ++it;
            printf( " %d", it->second );
        } while( it != hashTable.begin() );
        printf( " \n" );
    }
    return 0;
}
