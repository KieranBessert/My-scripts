# Lab7.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 24 Feb 2021
# Last edited by Kieran Bessert on 08 Mar 2021

# FOR TESTING PURPOSES ONLY
L0 = [ [1,2], [1,3], [3,4], [3,5], [4,5], [2,5] ]
L1 = [ [1,2], [1,3], [3,4], [3,5], [4,5] ]
# FOR TESTING PURPOSES ONLY

def Coloring(a):
    # FIND THE MAX DEGREE OF A VERTEX
    history = []
    for elements in a:
        if type(elements) is list:
            for integers in elements:
                history.append(integers)
                print(history) # For troubleshooting use only
    history.sort()
    print(history) # For troubleshooting use only
    # Assign the largest value to max
    max = history[-1]
    print(max) # For troubleshooting use only
    i = 1
    largest_degree = 0
    while (i <= max):
        if history.count(i) > largest_degree:
            largest_degree = history.count(i)
        i += 1
        print(largest_degree) # For troubleshooting use only
    # MAX DEGREE FOR A VERTEX IS KNOWN NOW
    if (largest_degree >= 7):
        return largest_degree
    #else:  
        # Brute force 2<=largest_degree<=5
        # to see if one of the following conditions are true
        # and if false, return other condition.
        # These are the only 2 possible cases.
        #   - class 1 if chromatic index = largest_degree
        #   - class 2 if chromatic index = largest_degree + 1


def Euler(a):
    # FIND THE MAX
    history = []
    split_path = []
    for elements in a:
        if type(elements) is list:
            for integers in elements:
                history.append(integers)
                print(history) # For troubleshooting use only
    history.sort()
    print(history) # For troubleshooting use only
    # Assign the largest value to max
    max = history[-1]
    # MAX IS NOW KNOWN
    color_history = [0]
    i = 1
    while (i <= max):
        color_history.append(0)
        for elements in a:
            if i in elements:
                color_history[i] += 1
        if color_history[i] > 2 and split_path == []:
            split_path = a[i]
            print("split_path ", split_path)
        i += 1
        print(color_history)
    # Count number of odd degree vertices
    odd_count = 0
    for num in color_history: 
        if num % 2 != 0:
            odd_count += 1
    print(odd_count) # For troubleshooting use only
    if odd_count != (0 or 2):
        return []
    else:
        for starting_point in a:
            count = 0
            path = []
            visited = []
            path.append(starting_point)
            visited.append(starting_point[0])
            visited.append(starting_point[1])
            while (len(path) != (len(a))):
                for points in a:
                    if ((visited[-1] in points) and (points[1] not in visited)):
                        path.append(points)
                        visited.append(points[1])
                        print(path)
                        print(visited)
                    elif ((visited[-1] in points) and (points[0] not in visited)):
                        path.append(points)
                        visited.append(points[0])
                        print(path)
                        print(visited)
                    else:
                        count += 1
                    if count == 10000:
                        break
                    # Split path is currently saved
                    # find a way to backtrack to the split path
                    # and try another path before picking new start point
                if count == 10000:
                    break
        return []

def Hamilton(a):
    path = []
    visited = []
    count = 0
    for starting_point in a:
        path.append(starting_point)
        visited.append(starting_point[0])
        visited.append(starting_point[1])
        while (len(path) != (len(a)-2)):
            for points in a:
                if ((visited[-1] in points) and (points[1] not in visited)):
                    path.append(points)
                    visited.append(points[1])
                elif ((visited[-1] in points) and (points[0] not in visited)):
                    path.append(points)
                    visited.append(points[0])
                else:
                    count += 1
            if count == 10000:
                return []
        return path
