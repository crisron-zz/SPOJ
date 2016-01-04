from collections import OrderedDict

t = raw_input()
t = int( t )

while t:
    t -= 1
    tc = raw_input()
    tc = int( tc )
    string = raw_input()
    hashTable = OrderedDict() 
    hashTable[ "TTT" ] = 0;
    hashTable[ "TTH" ] = 0;
    hashTable[ "THT" ] = 0;
    hashTable[ "THH" ] = 0;
    hashTable[ "HTT" ] = 0;
    hashTable[ "HTH" ] = 0;
    hashTable[ "HHT" ] = 0;
    hashTable[ "HHH" ] = 0;

    for i in range( 38 ):
        toss = string[ i : i + 3 ]
        hashTable[ toss ] += 1

    output = str( tc )
    for coins in hashTable.keys():
        output += " " + str( hashTable[ coins ] )

    output += " "
    print output
