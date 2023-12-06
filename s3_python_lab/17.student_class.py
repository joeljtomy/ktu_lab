# 18. Create a class student with attributes name, roll number and a method showData() for
#     showing the details. Create two instances of the class and call the method for each instance.
#     Develop a python program to implement the scenario.

class Student:
    def __init__(self):
        self.name = input("Enter name: ")
        self.roll_num = int(input("Enter roll number: "))
    def showData(self):
        print("Name:", self.name)
        print("Roll Number:", self.roll_num)

student1 = Student()
student2 = Student()

print("\nStudent 1:")
student1.showData()

print("\nStudent 2:")
student2.showData()


# Algorithm
# 1. Start

# 11. Stop
