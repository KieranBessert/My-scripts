#Coded by Kieran Bessert on 5/1/2020
#Last Edited on 5/1/2020
#The following code is a program that;
# - Asks the user for three name and phone number pairs.
# - Adds these pairs to a map.
# - Asks the user for a name to look up.
# - Responds with the phone number for that person.
# - Asks the user for a phone number.
# - Looks up the person who has that number.

print("WELCOME TO PHONE BOOK LOOK-UP PROGRAM!!!")
print("")
name1=input("Please enter a persons NAME! ")
print("")
number1=input("Please enter a persons PHONE NUMBER! ")
print("")
name2=input("Please enter another persons NAME! ")
print("")
number2=input("Please enter another persons PHONE NUMBER! ")
print("")
name3=input("Please enter a final persons NAME! ")
print("")
number3=input("Please enter a final persons PHONE NUMBER! ")
print("")
phoneBook = {name1 : number1,
             name2 : number2,
             name3 : number3}
nameSearch=input("Please enter one of the persons NAME to look up! ")
print("")
print("The PHONE NUMBER for ", nameSearch, " is ", phoneBook[nameSearch])
print("")
phoneBook = {number1 : name1,
             number2 : name2,
             number3 : name3}
numberSearch=input("Please enter one of the persons NUMBER to look up! ")
print("")
print("The NAME for ", numberSearch, " is ", phoneBook[numberSearch])
print("")
print("THANK YOU FOR USING THE PHONE BOOK LOOK-UP PROGRAM!!!")
