# Lab3.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 20 Jan 2021
# Last edited by Kieran Bessert on 20 Jan 2021

import math
    
# x = jug capacity 1
# y = jug capacity 2
# z = desired result in a jug
def Jug(x,y,z):
# Check for negitive integers
    if x<0 or y<0 or z<0:
        print("ERROR: Please utilize positive integers.")
        return
# Assign correct values
    if x>y:
        max = x
        min = y
    else:
        max = y
        min = x
# Check if problem is solvable 
    if (z % math.gcd(max,min)):
    # FOR TROUBLESHOOTING ONLY - check what gcd is
        #print("(math.gcd(max,min))",(math.gcd(max,min)))
    # FOR TROUBLESHOOTING ONLY - check if gcd is a multiple of z
        #print("(z%math.gcd(max,min))",(z%math.gcd(max,min)))
        print("ERROR: The amount cannot be obtained.")
        return
    if (max < z):
        print("ERROR: The desired amount %d is higher then the max %d."
              % (z,max))
        return
# Solve
    jug1 = 0
    jug2 = 0
    print("(%d,%d)->" % (jug1,jug2))
    while (jug2 != z) and (jug1 != z):
        if (jug1 == 0):
            # Fill smaller jug1
            jug1 = min
            print("\t(%d,%d)->" % (jug1,jug2))
        elif (jug2 == max):
            # Empty larger jug2
            jug2 = 0
            print("\t(%d,%d)->" % (jug1,jug2))
        elif((jug1+jug2) > max):
            # Fill jug2 with jug1 as much as possible
            jug1 = jug1 - (max - jug2)
            jug2 = max
            print("\t(%d,%d)->" % (jug1,jug2))
        else:
            # Fill jug2 with jug1
            jug2 = jug1 + jug2
            jug1 = 0
            print("\t(%d,%d)->" % (jug1,jug2))
    return

print("Please input 3 integer values:")
print("\tJug1 capacity, Jug2 capacity, Desired Amount")
