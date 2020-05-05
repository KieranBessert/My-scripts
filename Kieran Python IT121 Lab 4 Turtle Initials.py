#Coded by Kieran Bessert on 5/5/2020
#Last Edited on 5/5/2020
#The following code is a program that draws my initials with the Turtle Module

# Initiate turtle Module
import turtle
t=turtle.Pen()

# Lift pen, Set Position to TOP LEFT corner, place pen down
t.up()
t.setpos(-470,400)
t.down()
# K
t.right(90)
t.forward(100)
t.left(90)
t.forward(30)
t.left(90)
t.forward(40)
t.backward(40)
t.right(90)
t.forward(40)
t.left(90)
t.forward(50)
t.left(90)
t.forward(40)
t.backward(30)
t.right(90)
t.forward(50)
t.left(90)
t.forward(30)
t.left(90)
t.forward(40)
t.backward(40)
t.right(90)
t.forward(30)
# Lift pen, Set Position to BOTTOM RIGHT of K, place pen down
t.up()
t.setpos(-410,400)
t.down()
# B
t.right(180)
t.forward(60)
t.right(90)
t.forward(50)
t.right(90)
t.forward(30)
t.backward(40)
t.left(90)
t.forward(50)
t.right(90)
t.forward(60)
# Lift pen, Set Position to TOP MIDDLE of B, place pen down
t.up()
t.setpos(-380,375)
t.down()
# Top +
t.forward(15)
t.backward(30)
t.forward(15)
t.right(90)
t.forward(15)
t.backward(30)
# Lift pen, Set Position to BOTTOM MIDDLE of B, place pen down
t.up()
t.setpos(-375,325)
t.down()
# Bottom +
t.forward(15)
t.backward(30)
t.forward(15)
t.right(90)
t.forward(15)
t.backward(30)
# Lift pen, Set Position to BOTTOM MIDDLE of B, place pen down
t.up()
t.setpos(0,0)
t.down()
# FUN!
t.speed(1000)
t.color('blue', 'green')
while True:
    t.forward(200)
    t.right(173)
    t.circle(30)
    t.right(90)
t.done()
