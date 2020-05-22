#Coded by Kieran Bessert on 5/21/2020
#Last Edited on 5/21/2020
#The following code is a program that, starts a while loop
#Prompts the user for a shape to draw.
#Then prompts the user for how many of that shape to draw.
#Finally prompts the user for their favorite color.
#Given the user's response;
    #IF statements are used to decide what shape the user chose
    #Call a function to draw that shape
    #Start a for loop to iterate how many shapes
    #The program draws the appropriate shape in the favorite color

# FUNCTION DEFINITIONS
def exitProgram0():
    print("Goodbye!")
def drawCircle1(color):
    for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , color)
            turtle.speed(10)
            turtle.pensize(5)
            turtle.begin_fill()
            turtle.circle(200)
            turtle.end_fill()
            turtle.right(45)
def drawSquare2(color):
    for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , color)
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
def drawTriangle3(color):
    for x in range(many):
            turtle.bgcolor("cyan")
            turtle.color("magenta" , color)
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
def error():
    print("Not good at following directions, huh?")
    print("")
    print("That's ok!")
    print("")
    print("Try Again!!")
    print("")

# MAIN
# Initiate turtle Module
import turtle
t=turtle.Pen()
# Begin WHILE loop
while True:
    # Query user
    print("STOP!!!")
    print("")
    print("Answer me these questions three, ere a python grade I'll see...")
    print("")
    print("What would you like to draw?")
    print(" (S)quare")
    print(" (T)riangle")
    print(" (C)ircle")
    print(" (E)xit")
    shape1=input("      CHOICE: ")
    print("")
    # Exit IF statement
    if shape1 == ('E'):
        exitProgram0()
        break
    # Query user
    print("How many do you want?;")
    many=int(input("      CHOICE: "))
    print("")
    print("What is your favorite color?")
    color=input("      CHOICE: ")
    print("")
    # IF/ELIF/ELSE statements
    if shape1 == ('S'):
        drawSquare2(color)
    elif shape1 == ('T'):
        drawTriangle3(color)
    elif shape1 == ('C'):
        drawCircle1(color)
    else:
        error()
