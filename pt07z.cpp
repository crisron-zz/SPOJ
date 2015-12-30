#include <cstdio>
#include <vector>

#define MAX 10000

using namespace std;

class Tree {
    int n;
    vector< int > adj[ MAX + 2 ];
    int distFromVertex[ MAX + 2 ]; // Stores the distances of all the vertices from a particular vertex
    int visited[ MAX + 2 ];

    public:
        Tree( int n );
        void addEdge( int, int );
        void dfs( int );
        int getVertexForSecondDfs();
        void printDia( int );
        void clear();
};

int main() {
    int n, i, src, dest, v;
    scanf( "%d", &n );
    Tree tree( n );
    tree.clear();
    for( i = 0; i < ( n - 1 ); ++i ) {
        scanf( "%d%d", &src, &dest );
        tree.addEdge( src, dest );
    }
    // Do first DFS. This will populate the distFromVertex array with the distances of all the vertices from vertex 0
    tree.dfs( 0 );
    // Get the node farthest from 0 - this node will be one end of the diameter
    v = tree.getVertexForSecondDfs();
    // Clear the visited array and distances array before starting the second DFS
    tree.clear();
    // Store the distances of all the vertices from one end of the diameter
    tree.dfs( v );
    // Get the node farthest from one end of the diameter - that will be the second vertex of the diameter
    v = tree.getVertexForSecondDfs();
    // Diameter will be the distance of the second end of the diameter to the vertex that is farthest from it
    tree.printDia( v );
    return 0;
}

Tree::Tree( int m ) {
    n = m;
}

void Tree::addEdge( int src, int dest ) {
    adj[ src - 1 ].push_back( dest - 1 );
    adj[ dest - 1 ].push_back( src - 1 );
}

void Tree::dfs( int v ) {
    int i;
    int childNode;
    visited[ v ] = 1;
    for( i = 0; i < adj[ v ].size(); ++i ) {
        childNode = adj[ v ][ i ];
        if( !visited[ childNode ] ) {
            distFromVertex[ childNode ] = distFromVertex[ v ] + 1;
            dfs( childNode );
        }
    }
}

// This function gets the vertex that is
// farthest from the vertex with which we started the DFS
int Tree::getVertexForSecondDfs() {
    int i, farthestVertex;
    int maxDist = -1, vertexForSecondDfs;
    for( i = 0; i < n; ++i ) {
        if( distFromVertex[ i ] > maxDist ) {
            maxDist = distFromVertex[ i ];
            farthestVertex = i;
        }
    }
    return farthestVertex;
}

void Tree::printDia( int v ) {
    printf( "%d\n", distFromVertex[ v ] );
}

void Tree::clear() {
    int i;
    for( i = 0; i < n; ++i ) {
        distFromVertex[ i ] = 0;
        visited[ i ] = 0;
    }
}
