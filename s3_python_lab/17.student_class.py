# 18. Create a class student with attributes name, roll number and a method showData() for
#     showing the details. Create two instances of the class and call the method for each instance.
#     Develop a python program to implement the scenario.

class Student:
    def __init__(self, name, roll_number):
        self.name = name
        self.roll_number = roll_number

    def showData(self):
        print("Name:", self.name)
        print("Roll Number:", self.roll_number)

student1 = Student("John Doe", "12345")
student2 = Student("Jane Doe", "67890")

print("\nStudent 1:")
student1.showData()

print("\nStudent 2:")
student2.showData()


# Algorithm
# 1. Start

# 11. Stop
