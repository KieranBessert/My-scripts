#Coded by Kieran Bessert on 6/10/2020
#Last Edited on 6/10/2020
#Example code provided by Mike Massey
#The following code is a program that demonstrates the use of;
#   - Classes
#   - Derived Classes
#   - Inherited Attributes.

#Employee example provided by Mike Massey
#Common base class for all employees
class Employee:
    empCount = 0
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1
        self.empNum = Employee.empCount
    def displayCount(self):
        print ("%s is employee %d of %d" % (
            self.name,self.empNum,Employee.empCount))
    def displayEmployee(self):
        print ("Name : ", self.name, ", Salary: ", self.salary)
#This would create first object of Employee class
Luke = Employee("Luke", 2000)
#This would create second object of Employee class
Han = Employee("Han", 3000)
Luke.displayEmployee()
Han.displayEmployee()
Luke.displayCount()

#Manager class provided by Mike Massey
#derived from Employee that also has a department and can adjust salaries
class Manager(Employee):
    def __init__(self, name, salary, department):
        self.department = department
        Employee.__init__(self, name, salary)
    def displayManager(self):
        self.displayEmployee()
        print("%s manages the %s department." % (self.name, self.department))
    def adjustSalary(self, employee, amount, reason):
        employee.salary += amount
        print ("%s\'s new salary is %s." % (employee.name,employee.salary))
        print ("Reason for adjustment: %s" % reason)
#Create a new instance of a Manager
#which also includes all the attributes of an Employee
Darth=Manager("Darth",4500,"Death Star")
Darth.displayManager()
#Only Managers can adjust salaries
Darth.adjustSalary(Luke,-25,"Attacking my department")


#Wizard class written by Kieran Bessert
#derived from Employee that also has a proficiency and can change deparments
class Wizard(Employee):
    def __init__(self, name, salary, proficiency):
        self.proficiency = proficiency
        Employee.__init__(self, name, salary)
    def displayWizard(self):
        self.displayEmployee()
        print("%s proficient in %s spells." % (self.name, self.proficiency))
    def castSpell(self, employee, departmentNew, reason):
        employee.department = departmentNew
        print("%s has cast a spell targeting %s." % (self.name, employee.name))
        print("%s has has been changed to %s department." %
              (employee.name, employee.department))
        print(''' "%s" ''' % (reason))
#Create a new instance of a Wizard
#which also includes all the attributes of an Employee
Ben=Wizard("Ben",2000,"Mind Trickery")
Ben.displayWizard()
#Only Managers can adjust salaries
Ben.castSpell(Darth,"Rebel Alliance","There is Good in you, I know it to be true.")

        
