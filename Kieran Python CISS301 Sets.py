# Lab6.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 10 Feb 2021
# Last edited by Kieran Bessert on 17 Feb 2021

##############################################
def is_even(n):
    # Test for even input
    if (n == 0):
        return True
    else:
        # Mutual Recursion call
        return is_odd((n - 1))

def is_odd(n):
    # Test for odd input
    if (n == 0):
        return False
    else:
        # Mutual Recursion call
        return is_even((n - 1))
##############################################

# FOR TESTING PURPOSES ONLY
L0 = [ 1, [ 2, [ 3, 4 ] ] ] # Base
L1 = [ 1, [ 2, [ 3, 5 ] ] ] # False
L2 = [ 6, [ 2, [ 3, 5 ] ] ] # False
L3 = [ [ [ 4, 3 ], 2 ], 1 ] # True
L4 = [ [ [ 4, 5 ], 2 ], 1 ] # False
L5 = [ 1, [ 2, 3, 4 ] ] # False
# FOR TESTING PURPOSES ONLY
x = []
y = [1,2,3,4,5]
# FOR TESTING PURPOSES ONLY

def set_equal(a,b):
    if len(a) == len(b):
        return set_subset(a,b)
    else:
        return False

def set_subset(A,B):
    for A_elements in A:
        if type(A_elements) is not list:
            if A_elements not in B:
                return False
        else:
            for B_elements in B:
                if type(B_elements) is list:
                    return set_equal(B_elements,A_elements)
    return True
