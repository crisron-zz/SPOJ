import sys

for n in sys.stdin:
    n = int( n )
    if not n:
        print 0
    elif n == 1:
        print 1
    else:
        print 2 * n - 2
