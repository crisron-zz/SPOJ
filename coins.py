import sys
import pdb 

def calMaxAmt( coins ):
    if coins <= 4:
        return coins
    if coins in dp.keys():
        return dp[ coins ]
    dp[ coins ] = max( coins, calMaxAmt( coins / 2 ) + calMaxAmt( coins / 3 ) + calMaxAmt( coins / 4 ) )
    return dp[ coins ]

for line in sys.stdin:
    dp = {}
    maxAmt = calMaxAmt( int( line ) )
    print int( maxAmt )
