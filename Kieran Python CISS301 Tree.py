# Lab4.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 27 Jan 2021
# Last edited by Kieran Bessert on 27 Jan 2021

# FOR TESTING PURPOSES ONLY
V1 = ["a", "b", "c", "d", "e"]
V2 = ["a", "b", "c", "d", "e", "f"]
T1 = [ ["a","b"], ["b","c"], ["c","d"], ["d","e"] ]
T2 = [ ["a","b"], ["a","c"], ["a","d"], ["a","e"] ]
F = [ ["a","b"], ["b","c"], ["d","e"] ]
G = [ ["a","b"], ["b","c"], ["c","d"], ["d","e"], ["d","a"] ]
# FOR TESTING PURPOSES ONLY

# List1 represents the vertices of a graph in a list
#   Ex: [a,b,c,d,e]
# List2 represents the edges of a graph in list of two-element lists of vertices
#   Ex: [ [a,b], [b,c], [c,d], [d,e]]
def Tree(List1,List2):
    # Input test
    if not (isinstance(List1,list) and isinstance(List2,list)):
        print("ERROR: Please utilize lists.")
    # Test if Vertices appear in edge list
    for Vertex in List1:
        count = 0
        for Edge in List2:
            if Vertex in Edge:
                count += 1
        if count == 0:
            print("ERROR: Vertex "+Vertex+" does not appear in Edge List.")
            print("\t You are lost in a Forest.")
            return
    # Test if in a forest
    History=[]
    count = 0
    for Edge in List2:
        if Edge[0] not in History:
            History.append(Edge[0])
            count += 1
        if Edge[1] not in History:
            History.append(Edge[1])
        if count > 1:
            print("\t You are lost in a Forest.")
            return
    # Test if Edges form a cycle
    History=[]
    for Vertex in List1:
        if Vertex not in History:
            History.append(Vertex)
        for Edge in List2:
            if Vertex == Edge[0] and Edge[1] not in History:
                History.append(Edge[1])
            elif Vertex == Edge[0] and Edge[1] in History:
                print("ERROR: Vertex "+Edge[1]+" already visited.")
                print("\t You are going in cycles.")
                return
