# Lab5.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 3 Feb 2021
# Last edited by Kieran Bessert on 3 Feb 2021

# FOR TESTING PURPOSES ONLY
R1 = [ ["a","a"], ["b","b"], ["c","c"], ["d","d"] ] # True
R2 = [ ["a","a"], ["b","b"], ["c","c"], ["d","a"] ] # False
S1 = ["a", "b", "c", "d"]                           # True
S2 = ["a", "b", "c", "d", "e"]                      # False
Sym1 = [ ["a","b"], ["b","a"], ["b","c"], ["c","b"] ]   # True
Sym2 = [ ["a","b"], ["b","a"], ["b","c"], ["c","a"] ]   # False
T1 = [ ["a","b"], ["c","d"], ["e","f"] ]    # True
T2 = [ ["a","b"], ["b","c"], ["a","c"] ]    # True
T3 = [ ["a","b"], ["b","c"] ]               # False
# FOR TESTING PURPOSES ONLY

def Reflexive(L,S):
    # Test for Reflexivity
    for vertex in S:
        count = 0
        for pair in L:
            if vertex == pair[0] and vertex == pair[1]:
                count += 1
        if count == 0:
            print("ERROR: Vertex "+vertex+" is not reflexive.")
            return False
    return True

def Symmetric(L):
    # Test for Symmetry
    for pair in L:
        if pair[::-1] not in L:
            return False
    return True

def Transitive(L):
    # Test for Transitivity
    transitive = 1
    for x in L:
        for y in L:
            if x[1] == y[0]:
                transitive = 0
                for z in L:
                    if [x[0],y[1]] == z:
                        transitive = 1
    if transitive == 1:
        return True
    else:
        return False
