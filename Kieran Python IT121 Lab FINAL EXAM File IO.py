#Coded by Kieran Bessert on 6/17/2020
#Last Edited on 6/22/2020
#The following code is a program that;
    # - Reads in values from a file
    # - Stores those values in a list
    # - Draws a Graph based on those values
# All Comments are bullet points provided by Mike Massey
import csv
print("WELCOME TO THE FILE DATA DRAWER PROGRAM!!!")
print("")
print("")
# Print "Reading file into list..."
print("\tReading file into list...")
dataPoints=[]
# Read the file stockIndex.csv Preview the document into a list in your program. 
with open("stockIndex.csv","r") as csvfile:
    csvreader = csv.reader(csvfile)
    for row in csvreader:
        print(row[0],row[1])
        dataPoints.append(row)
print("")
# Print "The data in the list..."
print("\tThe data in the list...")
# Print the list that contains the data.
print(dataPoints)
print("")
print("")
# Print "Drawing the graph..."
print("\tDrawing the graph...")
print("")
# Draw the x and y axis lines, unit markings, and labels.
import turtle
t=turtle.Pen()
t.pencolor(0,0,0)
t.penup()
t.setpos(0,0)
t.write(0)
t.pendown()
# X-Axis
t.forward(100)
t.write(10)
t.left(90)
t.forward(200)
t.backward(210)
t.forward(10)
t.right(90)
t.forward(100)
t.write(20)
t.left(90)
t.forward(200)
t.backward(210)
t.forward(10)
t.right(90)
t.forward(100)
t.write(30)
t.left(90)
t.forward(200)
t.backward(210)
t.forward(10)
# Y-Axis
t.setpos(0,0)
t.write(0)
t.forward(50)
t.write(50)
t.right(90)
t.forward(300)
t.backward(310)
t.forward(10)
t.left(90)
t.forward(50)
t.write(100)
t.right(90)
t.forward(300)
t.backward(310)
t.forward(10)
t.left(90)
t.forward(50)
t.write(150)
t.right(90)
t.forward(300)
t.backward(310)
t.forward(10)
t.left(90)
t.forward(50)
t.write(200)
t.right(90)
t.forward(300)
t.backward(310)
t.forward(10)
t.left(90)
t.setpos(0,0)
# Print "Drawing the data..."
print("\tDrawing the data...")
print("")
# Draw the data.
# The first field of each row is the day, the second field is the index amount
#   (I would use a FOR loop to get x and y coordinates from the list
#       and use turtle or tkiner to draw the line to those coordinates.)
tempX = int(0)
tempY = int(0)
for row in dataPoints:
    x = int(row[0])
    x = x*10
    y = int(row[1])
    #   If the index amount went up, draw the line green.
    if y > tempY:
        t.pencolor((0,1,0))
        #   If the index amount went down, draw the line red.
    if y < tempY:
        t.pencolor((1,0,0))
    t.goto(x,y)
    tempX = int(x)
    tempY = int(y)
print("\tGraph Complete")
