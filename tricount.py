testCases = long( raw_input() )

while testCases:
    level = long( raw_input() )
    triangles = level * ( level + 2 ) * ( 2 * level + 1 ) / 8
    print triangles
    testCases = testCases - 1
