#include <cstdio>
#include <vector>

#define MAX 10000

using namespace std;

class Graph {
    int vertices;
    vector<int> adj[ MAX + 2 ]; // Adjacency list
    int visited[ MAX + 2 ];

    public:
        Graph( int n );
        void addEdge( int start, int end );
        void dfs( int v );
        bool isConnected();
};

Graph::Graph( int n ) {
    vertices = n;
    int i;
    for( i = 0; i < n; ++i ) {
        visited[ i ] = 0;
    }
}

void Graph::addEdge( int start, int end ) {
    adj[ start - 1 ].push_back( end - 1 );
    adj[ end - 1 ].push_back( start - 1 );
}

void Graph::dfs( int v ) { // Passing the starting vertex for dfs
    int i;
    visited[ v ] = 1;
    for( i = 0; i < adj[ v ].size(); ++i ) {
        if( !visited[ adj[ v ][ i ] ] ) {
            dfs( adj[ v ][ i ] );
        }
    }
}

bool Graph::isConnected() {
    int i;
    for( i = 0; i < vertices; ++i ) {
        if( !visited[ i ] ) {
            return false;
        }
    }
    return true;
}

int main() {
    int nodes, edges, i, u, v;
    scanf( "%d%d", &nodes, &edges );
    Graph gph( nodes );
    for( i = 0; i < edges; ++i ) {
        scanf( "%d%d", &u, &v );
        gph.addEdge( u, v );
    }
    gph.dfs( 0 );
    if( edges == ( nodes - 1 ) &&
        gph.isConnected() ) {
        printf( "YES\n" );
    } else {
        printf( "NO\n" );
    }
    return 0;
}
