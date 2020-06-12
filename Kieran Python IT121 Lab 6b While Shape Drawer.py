#Coded by Kieran Bessert on 5/21/2020
#Last Edited on 5/21/2020
#The following code is a program that, starts a while loop
#Prompts the user for a shape to draw.
#Then prompts the user for how many of that shape to draw.
#Given the user's response;
    #IF statements are used to decide what the user chose
    #Start a for loop to iterate how many shapes
    #the program draws the appropriate object

print("WELCOME TO THE SHAPE DRAWER PROGRAM!!!")
# Initiate turtle Module
import turtle
t=turtle.Pen()
# Begin WHILE loop
while True:
    # Query user
    print("")
    print("PLEASE SELECT A SHAPE TO DRAW;")
    print("1) Circle")
    print("2) Square")
    print("3) Triangle")
    print("0) EXIT")
    shape1=int(input("      CHOICE: "))
    print("")
    # Exit IF statement
    if shape1 == 0:
        print("Goodbye!")
        break
    # Query user
    print("HOW MANY DO YOU WANT?;")
    many=int(input("      CHOICE: "))
    print("")
    # IF/ELIF/ELSE statements
    if shape1 == 1:
        for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , "yellow")
            turtle.speed(10)
            turtle.pensize(5)
            turtle.begin_fill()
            turtle.circle(200)
            turtle.end_fill()
            turtle.right(45)
    elif shape1 == 2:
        for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , "yellow")
            turtle.speed(10)
            turtle.pensize(5)
            turtle.begin_fill()
            turtle.forward(150)
            turtle.right(90)
            turtle.forward(300)
            turtle.right(90)
            turtle.forward(300)
            turtle.right(90)
            turtle.forward(300)
            turtle.right(90)
            turtle.forward(150)
            turtle.end_fill()
            turtle.left(90)
            turtle.forward(50)
            turtle.left(90)
            turtle.forward(50)
            turtle.right(180)
    elif shape1 == 3:
        for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , "yellow")
            turtle.speed(10)
            turtle.pensize(5)
            turtle.begin_fill()
            turtle.left(120)
            turtle.forward(300)
            turtle.left(120)
            turtle.forward(300)
            turtle.left(120)
            turtle.forward(300)
            turtle.end_fill()
            turtle.right(45)
    else:
        print("Not good at following directions, huh?")
        print("")
        print("That's ok!")
        print("")
        print("Try Again!!")
