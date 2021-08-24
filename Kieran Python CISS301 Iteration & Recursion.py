# Lab2.py
# CISS 301 Winter Quarter 2021
# Coded by Kieran Bessert on 13 Jan 2021
# Last edited by Kieran Bessert on 17 Jan 2021

# Question 1
def One(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    i = 0
    Ans = 0
    while i <= Num:
        Ans += (i*i)
        i += 1
    return Ans
    
# Question 2
def Two(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    elif Num == 0:
        return 0
    else:
        return (Two(Num-1)+(Num*Num))
    
# Question 3
def Three(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    i = 0
    Ans = 0
    while i <= Num:
        Ans += i
        i += 1
    Ans *= Ans
    return Ans
    
# Question 4
def Helper(Num):
    if Num == 0:
        return 0
    else:
        return (Helper(Num-1)+Num)
def Four(Num):
    if Num < 0:
        print("ERROR: Please Utilize Positive Integers")
    elif Num == 0:
        return 0
    else:
        return Helper(Num)**2
