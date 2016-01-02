import math

n = raw_input()
n = int( n )
visited = [ n ]
result = 0
while n != 1:
    sumn = 0
    for i in str( n ):
        sumn += pow( int( i ), 2 )
    n = sumn
    if n in visited:
        result = -1
        break
    visited += [ n ]
    result += 1
print result
