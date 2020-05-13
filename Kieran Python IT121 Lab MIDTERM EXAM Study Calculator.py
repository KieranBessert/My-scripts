#Coded by Kieran Bessert on 5/12/2020
#Last Edited on 5/12/2020
#The following code is a program that;
#   - Prompts the user for how much studying they THINK they should be doing.
#   - Prompts the user for what their PLANNED number of DAYS/WEEK studying is.
#   - Prompts the user for what their ACTUAL number of HOURS/DAY studying is.
#   - Calculates the user's REQUIRED HOURS/DAY studying should be.
#   - Compares the user's REQUIRED HOURS/DAY to ACTUAL HOURS/DAY then;
#       - Informs the user of the difference in the 2 values;

# Declare Map to hold the values of hours should spend studying
classHrs = {"class1":0, "class2":0, "class3":0}
print("WELCOME TO THE STUDY CALCULATOR PROGRAM!!!")
print("")
# Declare variables to hold the value of type int and prompt user for data
class1Hours=int(
    input(
        "How many HOURS per WEEK should you spend studying for your 1ST class? "))
print("")
class2Hours=int(
    input(
        "How many HOURS per WEEK should you spend studying for your 2ND class? "))
print("")
class3Hours=int(
    input(
        "How many HOURS per WEEK should you spend studying for your 3RD class? "))
print("")
# Fill Map with values from the variables
classHrs = {"class1" : class1Hours,
            "class2" : class2Hours,
            "class3" : class3Hours}
# Declare variables to hold the value of type int and prompt user for data
plannedStudyDays=int(
    input(
        "How many DAYS per WEEK do you plan to spend studying altogether? "))
print("")
actualStudyHours=int(
    input(
        "How many HOURS a DAY are you actually studying altogether? "))
print("")
# Calculate the average number of HOURS/DAY the user SHOULD study
shouldStudyHours = (classHrs["class1"]+
                    classHrs["class2"]+
                    classHrs["class3"])/plannedStudyDays
print("According to your answers;")
# Declare variable to hold a string to print to screen
string1 = "You should spend an average of %.1f hours per day studying."
# Print the string with the calculated value (single decimal point)
print(string1 % (shouldStudyHours))
print("")
# Compare ACTUAL and SHOULD study hours, inform the user on the difference.
if actualStudyHours > shouldStudyHours:
    differenceHours = actualStudyHours - shouldStudyHours
    string1 = "You spend an extra %.1f HOURS per DAY studying."
    print(string1 % (differenceHours))
elif actualStudyHours < shouldStudyHours:
    differenceHours = shouldStudyHours - actualStudyHours 
    string1 = "You need to spend an extra %.1f HOURS per DAY studying."
    print(string1 % (differenceHours))
else:
    print("You are studying the perfect amount!")
    print("")
