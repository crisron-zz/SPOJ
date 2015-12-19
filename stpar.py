while True:
    numberOfTrucks = int( raw_input() )
    if not numberOfTrucks:
       break 

    truckOrder = raw_input()
    truckOrder = map( int, truckOrder.split()  ) # By default, split() is equivalent to split( ' ' )
    
    if numberOfTrucks == 1:
        print "yes"
    else:
        sideStreet = list() # Stack
        expected = 1
        for truck in truckOrder:
            if truck != expected:
                sideStreet.append( truck )
            else:
                expected = expected + 1
                while sideStreet:
                    top = sideStreet.pop()
                    if top == expected:
                        expected = expected + 1
                    else:
                        sideStreet.append( top )
                        break
        flag = 0
        while sideStreet:
            top = sideStreet.pop()
            if top == expected:
                expected = expected + 1
            else:
                flag = 1
                break
        if flag:
            print "no"
        else:
            print "yes"
