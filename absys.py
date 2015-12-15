import sys

def parseLine( line ):
    a = line.split( " " )[ 0 ]
    b = line.split( " " )[ 2 ]
    c = line.split( " " )[ 4 ]
    if "machula" in a:
        machula = int( c ) - int( b )
        machulaString = 0
    elif "machula" in b:
        machula = int( c ) - int( a )
        machulaString = 2
    else:
        machula = int( a ) + int( b )
        machulaString = 4
    return ( machula, machulaString )

t = raw_input()

for i in range( 2 * int( t ) ): 
    line = raw_input()
    if line is "":
        continue
    machula, machulaString = parseLine( line )
    line = line.replace( line.split( " " )[ machulaString ], str( machula ) )
    print line
