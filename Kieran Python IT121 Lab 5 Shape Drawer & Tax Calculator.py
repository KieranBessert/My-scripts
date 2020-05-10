#Coded by Kieran Bessert on 5/5/2020
#Last Edited on 5/9/2020
#The following code is a program that prompts the user for a shape to draw.
#Given the user's response;
    #IF statements are used to decide what the user chose
    #the program draws the appropriate object.
#Then the program prompts the user for their Tax Filing Status.
#Given the user's response;
    #IF statements are used to decide what the user chose
    #Sub-prompt the user for their Adjusted Gross income
    #Given the user's response;
        #IF statements are used to decide what the user chose
        #the program prints out the user's Marginal Tax Rate.

print("WELCOME TO THE SHAPE DRAWER PROGRAM!!!")
# Query user
print("")
print("PLEASE SELECT A SHAPE TO DRAW;")
print("1) Circle")
print("2) Square")
print("3) Triangle")
shape1=int(input("      CHOICE: "))
print("")
# Initiate turtle Module
import turtle
t=turtle.Pen()
# IF/ELIF/ELSE statements
if shape1 == 1:
    print("1) Circle")
    print("")
    turtle.bgcolor("cyan")
    turtle.color("magenta" , "yellow")
    turtle.speed(10)
    turtle.pensize(5)
    turtle.begin_fill()
    turtle.circle(200)
    turtle.end_fill()
elif shape1 == 2:
    print("2) Square")
    print("")
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
elif shape1 == 3:
    print("3) Triangle")
    print("")
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
else:
    print("Not good at following directions, huh?")
    print("")
    print("That's ok!")
    print("")
    print("Try Again!!")
    print("")
    print("")

print("WELCOME TO THE TAX CALCULATOR PROGRAM!!!")
print("")
# Query user
print("PLEASE SELECT YOUR TAX FILING STATUS;")
print("1) Single")
print("2) Married (Filing Jointly)")
print("3) Married (Filing Seperately)")
print("4) Head of Household")
taxFilingStatus=int(input("      CHOICE: "))
print("")
# IF/ELIF/ELSE statements
if taxFilingStatus == 1:
    # Sub-Query user
    print("PLEASE SELECT YOUR ADJUSTED GROSS INCOME;")
    print("1) $0 - $9,875")
    print("2) $9,875 - $40,125")
    print("3) $40,125 - $85,525")
    print("4) $85,525 - $163,300")
    print("5) $163,300 - $207,350")
    print("6) $207,350 - $518,400")
    print("7) Over $518,400")
    adjustedGrossIncome=int(input("      CHOICE: "))
    print("")
    # Sub-IF/ELIF/ELSE statements
    if adjustedGrossIncome == 1:
        print("Your Marginal Tax Rate is;")
        print("10%")
        print("")
    elif adjustedGrossIncome == 2:
        print("Your Marginal Tax Rate is;")
        print("12%")
        print("")
    elif adjustedGrossIncome == 3:
        print("Your Marginal Tax Rate is;")
        print("22%")
        print("")
    elif adjustedGrossIncome == 4:
        print("Your Marginal Tax Rate is;")
        print("24%")
        print("")
    elif adjustedGrossIncome == 5:
        print("Your Marginal Tax Rate is;")
        print("32%")
        print("")
    elif adjustedGrossIncome == 6:
        print("Your Marginal Tax Rate is;")
        print("35%")
        print("")
    elif adjustedGrossIncome == 7:
        print("Your Marginal Tax Rate is;")
        print("37%")
        print("")
    else:
        print("Not good at following directions, huh?")
        print("")
elif taxFilingStatus == 2:
    # Sub-Query user
    print("PLEASE SELECT YOUR ADJUSTED GROSS INCOME;")
    print("1) $0 - $19,750")
    print("2) $19,750 - $80,250")
    print("3) $80,250 - $117,050")
    print("4) $117,050 - $326,600")
    print("5) $326,600 - $414,700")
    print("6) $414,700 - $622,050")
    print("7) Over $622,050")
    adjustedGrossIncome=int(input("      CHOICE: "))
    print("")
    # Sub-IF/ELIF/ELSE statements
    if adjustedGrossIncome == 1:
        print("Your Marginal Tax Rate is;")
        print("10%")
        print("")
    elif adjustedGrossIncome == 2:
        print("Your Marginal Tax Rate is;")
        print("12%")
        print("")
    elif adjustedGrossIncome == 3:
        print("Your Marginal Tax Rate is;")
        print("22%")
        print("")
    elif adjustedGrossIncome == 4:
        print("Your Marginal Tax Rate is;")
        print("24%")
        print("")
    elif adjustedGrossIncome == 5:
        print("Your Marginal Tax Rate is;")
        print("32%")
        print("")
    elif adjustedGrossIncome == 6:
        print("Your Marginal Tax Rate is;")
        print("35%")
        print("")
    elif adjustedGrossIncome == 7:
        print("Your Marginal Tax Rate is;")
        print("37%")
        print("")
    else:
        print("Not good at following directions, huh?")
        print("")
elif taxFilingStatus == 3:
    # Sub-Query user
    print("PLEASE SELECT YOUR ADJUSTED GROSS INCOME;")
    print("1) $0 - $9,875")
    print("2) $9,875 - $40,125")
    print("3) $40,125 - $85,525")
    print("4) $85,525 - $163,300")
    print("5) $163,300 - $207,350")
    print("6) $207,350 - $311,025")
    print("7) Over $311,025")
    adjustedGrossIncome=int(input("      CHOICE: "))
    print("")
    # Sub-IF/ELIF/ELSE statements
    if adjustedGrossIncome == 1:
        print("Your Marginal Tax Rate is;")
        print("10%")
        print("")
    elif adjustedGrossIncome == 2:
        print("Your Marginal Tax Rate is;")
        print("12%")
        print("")
    elif adjustedGrossIncome == 3:
        print("Your Marginal Tax Rate is;")
        print("22%")
        print("")
    elif adjustedGrossIncome == 4:
        print("Your Marginal Tax Rate is;")
        print("24%")
        print("")
    elif adjustedGrossIncome == 5:
        print("Your Marginal Tax Rate is;")
        print("32%")
        print("")
    elif adjustedGrossIncome == 6:
        print("Your Marginal Tax Rate is;")
        print("35%")
        print("")
    elif adjustedGrossIncome == 7:
        print("Your Marginal Tax Rate is;")
        print("37%")
        print("")
    else:
        print("Not good at following directions, huh?")
        print("")
elif taxFilingStatus == 4:
    # Sub-Query user
    print("PLEASE SELECT YOUR ADJUSTED GROSS INCOME;")
    print("1) $0 - $14,100")
    print("2) $14,100 - $53,700")
    print("3) $53,700 - $85,500")
    print("4) $85,500 - $163,300")
    print("5) $163,300 - $207,350")
    print("6) $207,350 - $518,400")
    print("7) Over $518,400")
    adjustedGrossIncome=int(input("      CHOICE: "))
    print("")
    # Sub-IF/ELIF/ELSE statements
    if adjustedGrossIncome == 1:
        print("Your Marginal Tax Rate is;")
        print("10%")
        print("")
    elif adjustedGrossIncome == 2:
        print("Your Marginal Tax Rate is;")
        print("12%")
        print("")
    elif adjustedGrossIncome == 3:
        print("Your Marginal Tax Rate is;")
        print("22%")
        print("")
    elif adjustedGrossIncome == 4:
        print("Your Marginal Tax Rate is;")
        print("24%")
        print("")
    elif adjustedGrossIncome == 5:
        print("Your Marginal Tax Rate is;")
        print("32%")
        print("")
    elif adjustedGrossIncome == 6:
        print("Your Marginal Tax Rate is;")
        print("35%")
        print("")
    elif adjustedGrossIncome == 7:
        print("Your Marginal Tax Rate is;")
        print("37%")
        print("")
    else:
        print("Not good at following directions, huh?")
        print("")
else:
    print("Not good at following directions, huh?")
    print("")
