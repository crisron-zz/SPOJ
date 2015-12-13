import sys

def calMaxAmt( coins ):
    if coins <= 4:
        return coins
    if coins in dp.keys():
        return dp[ coins ]
    # Memoization
    dp[ coins ] = max( coins, calMaxAmt( coins / 2 ) + calMaxAmt( coins / 3 ) + calMaxAmt( coins / 4 ) )
    return dp[ coins ]

# Input until EOF
for line in sys.stdin:
    # Reset the dictionary for every testcase
    dp = {}
    maxAmt = calMaxAmt( int( line ) )
    print int( maxAmt )
