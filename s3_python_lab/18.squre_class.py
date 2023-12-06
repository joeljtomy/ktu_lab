# 18. Create a class Square with attributes number, output and methods calculate and display.
#     Create instance of the class and call method calculate to compute square of the number
#     and call method display to print output.

class Square:
    def __init__(self, num):
        self.number = num
        self.output = 0
    def calculate(self):
        self.output = self.number ** 2
    def display(self):
        print("number:", self.number)
        print("output:", self.output)

num = int(input("Enter a number: "))
square = Square(num)
square.calculate()
square.display()


# Algorithm
# 1. Start 

# 11. Stop
