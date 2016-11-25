#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define MAX 50002
#define SEGTREEMAX 200000 

using namespace std;

struct segTreeNode {
    int maxPrefixSum;
    int maxSuffixSum;
    int maxSubarraySum;
    int totalSum;
};

int findMaxOf3( const int& a, const int& b, const int& c ) {
    return ( max( a, max( b, c ) ) );
}

int findMaxPrefixSum( const segTreeNode& left, const segTreeNode& right ) {
    return max( left.maxPrefixSum,
                left.totalSum + right.maxPrefixSum );
}

int findMaxSuffixSum( const segTreeNode& left, const segTreeNode& right ) {
    return max( right.maxSuffixSum,
                right.totalSum + left.maxSuffixSum );
}

int findMaxSubarraySum( const segTreeNode& left, const segTreeNode& right ) {
    return findMaxOf3( left.maxSubarraySum,
                       right.maxSubarraySum,
                       left.maxSuffixSum + right.maxPrefixSum );
}

void buildSegmentTreeUtil( segTreeNode segmentTree[], const int& rangeStart, const int& rangeEnd,
                          const int& segmentTreeIndex, const int arr[], const int& n ) {
    if( rangeStart == rangeEnd ) {
        segmentTree[ segmentTreeIndex ].maxPrefixSum = arr[ rangeStart ];
        segmentTree[ segmentTreeIndex ].maxSuffixSum = arr[ rangeStart ];
        segmentTree[ segmentTreeIndex ].maxSubarraySum = arr[ rangeStart ];
        segmentTree[ segmentTreeIndex ].totalSum = arr[ rangeStart ];
        return;
    }

    int mid = rangeStart + ( rangeEnd - rangeStart ) / 2;
    int left = 2 * segmentTreeIndex + 1;
    int right = 2 * segmentTreeIndex + 2;

    buildSegmentTreeUtil( segmentTree, rangeStart, mid,
                          2 * segmentTreeIndex + 1, arr, n );
    buildSegmentTreeUtil( segmentTree, mid + 1, rangeEnd,
                          2 * segmentTreeIndex + 2, arr, n );

    segmentTree[ segmentTreeIndex ].maxPrefixSum = 
                          findMaxPrefixSum( segmentTree[ left ], segmentTree[ right ] );
    segmentTree[ segmentTreeIndex ].maxSuffixSum = 
                          findMaxSuffixSum( segmentTree[ left ], segmentTree[ right ] );
    segmentTree[ segmentTreeIndex ].maxSubarraySum =
                          findMaxSubarraySum( segmentTree[ left ], segmentTree[ right ] );
    segmentTree[ segmentTreeIndex ].totalSum = segmentTree[ left ].totalSum + segmentTree[ right ].totalSum;
}

void buildSegmentTree( segTreeNode segmentTree[], const int arr[], const int& n ) {
    buildSegmentTreeUtil( segmentTree, 0, n - 1, 0, arr, n );
}

void findSegTreeIdxForInterestingRanges( vector< int >& segTreeIdxArr,
        const int& start, const int& end, const int& rangeStart,
        const int& rangeEnd, const int& segmentTreeIndex ) {
    if( rangeStart >= start && rangeEnd <= end ) {
        segTreeIdxArr.push_back( segmentTreeIndex );
        return;
    }
    if( rangeStart > end || rangeEnd < start ) {
        return;
    }
    int mid = rangeStart + ( rangeEnd - rangeStart ) / 2;
    findSegTreeIdxForInterestingRanges( segTreeIdxArr, start, end,
            rangeStart, mid, 2 * segmentTreeIndex + 1 );
    findSegTreeIdxForInterestingRanges( segTreeIdxArr, start, end,
            mid + 1, rangeEnd, 2 * segmentTreeIndex + 2 );
}

int query( const segTreeNode segmentTree[], const int& start,
           const int& end, const int& n ) {
    vector< int > segTreeIdx;
    findSegTreeIdxForInterestingRanges( segTreeIdx, start, end, 0, n - 1, 0 );
    
    int totalSum = -2e9;
    int maxSubarraySum = -2e9;
    for( int i = 0; i < segTreeIdx.size(); ++i ) {
        const segTreeNode node = segmentTree[ segTreeIdx[ i ] ];
        maxSubarraySum = max( maxSubarraySum,
                              node.maxSubarraySum );
        maxSubarraySum = max( maxSubarraySum,
                              totalSum + node.maxPrefixSum );
        totalSum = max( node.maxSuffixSum,
                        totalSum + node.totalSum );
    }
    return maxSubarraySum;
}

int main() {
    int n, m, start, end, arr[ MAX ];
    cin >> n;
    for( int i = 0; i < n; ++i ) {
        cin >> arr[ i ];
    }
    segTreeNode segmentTree[ SEGTREEMAX ];
    buildSegmentTree( segmentTree, arr, n );

    cin >> m;
    for( int i = 0; i < m; ++i ) {
        cin >> start >> end;
        start--; end--;
        cout << query( segmentTree, start, end, n ) << endl;
    }
    return 0;
}

