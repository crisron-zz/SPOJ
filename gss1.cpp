#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define MAX 50002
// Below code can be used to calculate the max
// height of segment tree
// int heightSegmentTree = ceil( log2( n ) );
// int maxSegmentTreeSize = 2 * pow( 2, heightSegmentTree ) - 1;
// cout << "size " << maxSegmentTreeSize << endl;
#define SEGTREEMAX 131100

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
    return findMaxOf3( left.maxPrefixSum,
                       left.totalSum + right.maxPrefixSum,
                       left.totalSum + right.totalSum );
}

int findMaxSuffixSum( const segTreeNode& left, const segTreeNode& right ) {
    return findMaxOf3( right.maxSuffixSum,
                       right.totalSum + left.maxSuffixSum,
                       right.totalSum + left.totalSum );
}

// For the subarray from left to right, the max sum subarray can be contained:
// 1. Completely within left
// 2. Completely within right
// 3. Partially within the right end of left and partially within the left end of right
int findMaxSubarraySum( const segTreeNode& left, const segTreeNode& right ) {
    return findMaxOf3( left.maxSubarraySum,
                       right.maxSubarraySum,
                       left.maxSuffixSum + right.maxPrefixSum );
}

int maxSumSubarray( const int arr[], const int& rangeStart, const int& rangeEnd ) {
    int localMax = arr[ rangeStart ];
    int globalMax = arr[ rangeStart ];
    for( int i = rangeStart + 1; i <= rangeEnd; ++i ) {
        localMax = max( arr[ i ], localMax + arr[ i ] );
        globalMax = max( localMax, globalMax );
    }
    return globalMax;
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
    // Current range is the exact( or narrower ) range ( than ) queried
    if( rangeStart >= start && rangeEnd <= end ) {
        segTreeIdxArr.push_back( segmentTreeIndex );
        return;
    }
    // This segment doesn't cover any index of the queried range
    if( rangeStart > end || rangeEnd < start ) {
        return;
    }
    int mid = rangeStart + ( rangeEnd - rangeStart ) / 2;
    findSegTreeIdxForInterestingRanges( segTreeIdxArr, start, end,
            rangeStart, mid, 2 * segmentTreeIndex + 1 );
    findSegTreeIdxForInterestingRanges( segTreeIdxArr, start, end,
            mid + 1, rangeEnd, 2 * segmentTreeIndex + 2 );
}

// start - end => range queried
// rangeStart - rangeEnd => range of the current segment
int query( const segTreeNode segmentTree[], const int& start,
           const int& end, const int& n ) {
    // segTreeIdx is an array of indices of the nodes of the
    // segment tree which are of interest to us.
    // Suppose that there are 8 elements in the given array
    // and the range queried is 2-6, then segTreeIdx will contain
    // 3 elements. Those 3 elements will be the segment tree node
    // indices corresponding to the ranges 2-3, 4-5 and 6-6
    vector< int > segTreeIdx;
    findSegTreeIdxForInterestingRanges( segTreeIdx, start, end, 0, n - 1, 0 );
    
    int totalSum = INT_MIN;
    int maxSubarraySum = INT_MIN;
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
        start--; end--; // Make the range 0 index based
        cout << query( segmentTree, start, end, n ) << endl;
    }
    return 0;
}

