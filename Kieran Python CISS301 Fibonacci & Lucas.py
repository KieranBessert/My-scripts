# Lab1.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 6 Jan 2021
# Last edited by Kieran Bessert on 6 Jan 2021

# Question 1
def Fib(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    elif Num == 0 or Num == 1:
        return Num
    else:
        return (Fib(Num-1)+Fib(Num-2))

# Question 2
def Luc(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    elif Num == 0:
        return 2
    elif Num == 1:
        return Num
    else:
        return (Luc(Num-1)+Luc(Num-2))

# Question 3
def Pair(Num):
    return (Fib(Num+2)-Fib(Num-2))

# Question 4
# Luc and Pair have the same outputs for each input equal to 2 or higher.
# This is because a negitive number is supplied for the second argument in pair
#   if the value provided is under 2.
# Otherwise they preform the same computation.
